#include <stdio.h>

#define WORDS 10
#define RETURN '\n'
#define BLANK ' '

/* print a histogram of lengths of words in input horizontally */

main()
{
	int words[WORDS];
	int c, i;

	for (i = 0; i < WORDS; ++i)
		words[i] = 0;

	i = 0;
	while ((c = getchar()) != RETURN)
	{
		if (c != BLANK)
			++words[i];
		else
			++i;

	}

	for (i = 0; i < WORDS; ++i)
	{
		for (int j = 0; j < words[i]; ++j)
			printf("-");
		printf("\n");

	}

}
