#include <stdio.h>

#define BACKSPACE '\b'
#define BLANK ' '

/* copy input to output, replacing each string of one or more blanks by a single blank */

main()
{
	int blanks;
	int c;

	blanks = 0;

	while ((c = getchar()) != EOF)
	{
		putchar(c);

		if (c == BLANK)
			++blanks;
		else
			blanks = 0;

		if(blanks > 1)
			putchar(BACKSPACE);

	}

}
