#include <stdio.h>

main()
{
	int a = 5, b = 10;
	int *x = &a;
	int *y = &b;

	printf("a = %d, b = %d\n", a, b);
	printf("x = %d, y = %d\n", *x, *y);
	x = y;
	printf("x = %d, y = %d\n", *x, *y);
	*x += b;
	printf("x = %d, y = %d\n", *x, *y);
	printf("a = %d, b = %d\n", a, b);

	return(0);
}
