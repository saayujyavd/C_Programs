#include <stdio.h>

#define BLANK ' '
#define TAB '\t'
#define RETURN '\n'

/* print input one word per line */

main()
{
	int c;

	while ((c = getchar()) != EOF)
	{
		putchar(c);
		if (c == BLANK || c == TAB)
			putchar(RETURN);

	}

}
