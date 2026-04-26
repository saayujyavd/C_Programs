#include <stdio.h>

unsigned lower(unsigned);

/* Write the function lower, which converts upper-case letters to lower-case, with a conditional expression instead of if-else */

main()
{
	unsigned ch = 'O';

	printf("%c\n", lower(ch));

	return(0);

}

unsigned lower(unsigned c)
{
	return((c >= 'A' && c <= 'z') ? (c + 'a' - 'A') : (c));

}
