#include <stdio.h>

add(int, int);
sub(int, int);

main()
{
	int first = 5, second = -88;
	
	printf("%d\n%d\n", add(first, second), sub(first, second));

	return(0);

}

add(int a, int b)
{
	return(a + b);

}
