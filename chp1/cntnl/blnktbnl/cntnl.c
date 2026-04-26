#include <stdio.h>

#define BLANK ' '
#define TAB '\t'
#define RETURN '\n'

/* count blanks, tabs, and newlines */

main()
{
	int blanks, tabs, newlines;
	int c;

	blanks = 0;
	tabs = 0;
	newlines = 0;

	for (int chr = 0; (c = getchar()) != EOF; ++chr)
	{
		if (c == BLANK)
			++blanks;
		else if (c == TAB)
			++tabs;
		else if (c == RETURN)
			++newlines;

	}
	printf("%d\n%d\n%d\n", blanks, tabs, newlines);

}
