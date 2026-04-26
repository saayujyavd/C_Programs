#include <stdio.h>
#include <stdlib.h>
#include "mymalloc.h"

#define MAXDIFFS	100

main()
{
	void* mycalloc(size_t, size_t);
	/* ... */
	ptrdiff_t* nums;
	int i;

	if (!(nums = (ptrdiff_t*)mycalloc(MAXDIFFS, sizeof(nums))))
	{
		fprintf(stderr, "mycalloc: err\n");
		exit(1);
	}
	for (i = 0; i < MAXDIFFS; ++i) printf("%td ", *(nums + i));

	if (nums) myfree(nums);
	nums = NULL;
	return(0);
}

/* mycalloc: returns a ptr. to n objs. of size 'size', with strg. init'd. to zero */
void* mycalloc(size_t n, size_t size)
{
	long double* nobjs;	// 'long double' for worst-case scenario
	int i;
	
	if (!(nobjs = (long double*)mymalloc(n * size))) return(NULL);
	else for (i = 0; i < n; ++i) *(nobjs + i) = 0.0;
	return((void*)nobjs);
}
