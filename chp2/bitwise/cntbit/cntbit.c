#include <stdio.h>

fbitcount(unsigned);

/*	In two's complement number system, x &= (x - 1) deletes the rightmost 1-bit in x.
	Use this observation to write a faster fbitcount.
*/

main()
{
	unsigned n = 16;
	
	printf("%d\n", fbitcount(n));

	return(0);

}

int sbitcount(unsigned x)
{
	int b;

	for (b = 0; x != 0; x >>= 1)
	{
		if (x & 01)
			++b;

	}

	return(b);

}

int fbitcount(unsigned x)
{
	int b;

	b = 0;
	while (x &= (x - 1))
		++b;

	return(++b);

}
