#include <stdio.h>
#include <Windows.h>
#include <memoryapi.h>

typedef long Align;	/* instance of the most restrictive alignment type, which have arbitrarily been made a long */

union header
{
	struct
	{
		union header* nxtfreeblk;	/* next block if on free list */
		unsigned size;				/* size of this blk */
	} s;
	/* ... */
	Align x;	/* using to force each header to be aligned on worst-case boundary */
};

typedef union header Header;	/* because didn't want to always right the whole words 'union header' */

/* we'll need an empty block (calling it the base block) to get started */
static Header base;				/* static because base should not be re-initialized after every call to mymalloc */
/* we'll need a starting point of the free space */
static Header* freep = NULL;	/* start of free list of blocks, same reason for static-ness of freep as of base */

/* malloc: general-purpose storage allocator */
void* mymalloc(unsigned nbytes)
{	
	Header* mymorecore(unsigned);
	void myfree(void*);

	Header* p, * prevp;
	unsigned nunits;

	/* to simplify alignment, making all blocks multiples of the header size */
	nunits = ((nbytes + sizeof(Header) - 1) / sizeof(Header)) + 1;

	/*	
	if freep is NULL, as it is at the first call of malloc, then a degenerate free list is created;
	it contains one block of size zero, & points to itself.	
	*/
	if ((prevp = freep) == NULL)	/* no free block yet */
	{
		base.s.nxtfreeblk = freep = prevp = &base;
		base.s.size = 0;
	}

	/*
	now the search for a free block of adequate size begins at the point 'freep'
	where the last block was found; this strategy helps keep the list homogeneous.
	*/
	for (p = prevp->s.nxtfreeblk; ; prevp = p, (p = p->s.nxtfreeblk))
	{
		if (p->s.size >= nunits)	/* big enough space */
		{
			if (p->s.size == nunits)	/* space exactly equal */
				prevp->s.nxtfreeblk = p->s.nxtfreeblk;	/*	since this space will now be given to user,
															the block pointing to this space as it's next free space,
															should now point to that free block,
															which is pointed by this block.
														*/
			else    /*	since the required space is less than available space,
						we are going to give the tail end of this block to the user,
						so that we just have to change the size variable of this block.
					*/
			{
				p->s.size -= nunits;	/* decrease the size of the free block from the tail end by the size asked by user */
				p += p->s.size;			/* increment p to the base address to be given to user */
				p->s.size = nunits;		/* assign this block the size asked by user */
			}

			freep = prevp;
			return((void*)(p + 1));	/* the pointer returned by malloc points at free space, but not at the header itself, therefore 'p + 1' */
		}
		if (p == freep)							// even after going through the arena, if still p points to free space,
		{										// (because we want contiguous free space allocation)
			if ((p = mymorecore(nunits)) == NULL) // only then ask OS for more space
				return(NULL); /* no space left to be given to user */
		}

	}

}

#define NALLOC	1024	/* minimum #units to request */

/* morecore: ask system for more memory */
Header* mymorecore(unsigned nu)
{
	if (nu < NALLOC)
		nu = NALLOC;

	Header* pspace = (Header*)VirtualAlloc(
		NULL, nu * sizeof(Header),
		MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE
	);
	if (pspace == NULL)
		return NULL;

	pspace->s.size = nu;
	myfree((void*)(pspace + 1));  // insert into free list via myfree
	return freep;                 // now freep points into the new block
}

/* free: put block back in the free block list */
void myfree(void* ap)
{
	Header* p, *pblockh;

	pblockh = ((Header*)ap - 1);	// point to block header;
	/* scan the free block list, starting at freep, looking for the place to insert the free block */
	for (p = freep; !(pblockh > p && pblockh < p->s.nxtfreeblk); p = p->s.nxtfreeblk)
		if (p >= p->s.nxtfreeblk && (pblockh > p || pblockh < p->s.nxtfreeblk))
			break;	/* free block at start or end of arena */

	if (pblockh + pblockh->s.size == p->s.nxtfreeblk)	/* join to upper nbr */
	{
		pblockh->s.size += p->s.nxtfreeblk->s.size;
		pblockh->s.nxtfreeblk = p->s.nxtfreeblk->s.nxtfreeblk;
	}
	else
		pblockh->s.nxtfreeblk = p->s.nxtfreeblk;
	if (p + p->s.size == pblockh)	/* join to lower nbr */
	{
		p->s.size += pblockh->s.size;
		p->s.nxtfreeblk = pblockh->s.nxtfreeblk;
	}
	else
		p->s.nxtfreeblk = pblockh;

	freep = p;
}
