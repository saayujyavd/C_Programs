#include <stdio.h>

#define RETURN '\n'
#define BLANK ' '
#define TAB '\t'

#define INWRD 1
#define OUTWRD 0

/* count lines, words, and characters in input */

main()
{
	int lines, words, chars;
	int c;
	int state;

	lines = words = chars = 0;
	state = OUTWRD;

	while ((c = getchar()) != EOF)
	{
		++chars;

		if (c == RETURN)
			++lines;
		if (c == BLANK || c == TAB || c == RETURN)
			state = OUTWRD;
		else if(state == OUTWRD)
		{
			state = INWRD;
			++words;

		}

	}
	printf("%d\n%d\n%d\n", lines, words, chars);

}
