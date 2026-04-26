#include <stdio.h>

#define	swap(t, x, y)	t = x; x = y; y = t;

main()
{
	int a = 5, b = 10;
	int tmp;

	printf("Before:\na = %d, b = %d\n", a, b);
	swap(tmp, a, b);
	printf("After:\na = %d, b = %d\n", a, b);

	return(0);
}
