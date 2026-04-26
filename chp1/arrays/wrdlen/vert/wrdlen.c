#include <stdio.h>

#define BLANK ' '
#define WORDS 10
#define RETURN '\n'

/* print histogram of lengths of words in input */

main()
{
	int words[WORDS];
	int c, i;

	for (i = 0; i < WORDS; ++i)
		words[i] = 0;

	i = 0;
	while ((c = getchar()) != RETURN)
	{
		if (i <= WORDS)
		{
			if (c != BLANK)
				++words[i];
			else if (c == BLANK)
				++i;

		}

	}

	i = 0;
	for (int y = 0; ; ++y)
	{
		for(int x = 0; x < WORDS; ++x)
		{
			printf("|\t");
			--words[i];
			++i;

			if (words[i] == 0)
				printf(" \t");

		}
		printf("\n");

	}

}
