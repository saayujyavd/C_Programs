#include <stdio.h>

/* exploring call by-value asset */

int add(int, int);

main()
{
	int x, y, sum;

	x = y = 5;
	sum = add(x, y);
	printf("%d\n%d\n%d\n", sum, x, y);

	return(0);

}

int add(int a, int b)
{
	printf("Initially...\na = %d\nb = %d\n", a, b);
	--a;
	++b;
	printf("Finally...\na = %d\nb = %d\n", a, b);

	return(a + b);

}
