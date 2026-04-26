#include <stdio.h>

rightrot(int, int);

/* return the value of integer x rotated to right by n bit positions */

main()
{
	int a, b;

	a = b = 2;
	while(a++ < 20)
		printf("%2d rightrot %d = %d\n", a, b, rightrot(a, b));

	return(0);

}

int rightrot(int x, int n)
{
	return(x >> n);

}
