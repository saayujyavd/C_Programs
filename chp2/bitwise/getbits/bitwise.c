#include <stdio.h>

unsigned getbits(unsigned ux, int ip, int in);

/* get n bits from position p */

main()
{
	int n;

	n = 101;
	printf("%d\n", getbits(n, 4, 3));

	return(0);

}

unsigned getbits(unsigned x, int p, int n)
{
	return(x >> (p + 1 - n) & ~(~0 << n));

}
