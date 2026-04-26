#include <stdio.h>

#define TAB '\t'
#define BACKSPACE '\b'
#define BACKSLASH '\\'

/* copy input to output, replacing each tab by \t, each backspace by \b, and each backslash by \\ */

main()
{
	int c;

	while ((c = getchar()) != EOF)
	{
		putchar(c);

		if (c == TAB)
		{
			putchar(BACKSPACE);
			printf("\\t");

		}
		if (c == BACKSPACE)
		{
			putchar(BACKSPACE);
			printf("\\b");

		}
		if (c == BACKSLASH)
		{
			putchar(BACKSPACE);
			printf("\\\\");

		}

	}

}
