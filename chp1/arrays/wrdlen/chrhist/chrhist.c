#include <stdio.h>

#define VWLS 5
#define RETURN '\n'

/* print histogram of frequencies of different characters in input */

main()
{
	int chrs[VWLS];
	int c;

	for (int i = 0; i < VWLS; ++i)
		chrs[i] = 0;

	while ((c = getchar()) != RETURN)
	{
		switch (c)
		{
		case 'a':
			++chrs[0];
			break;

		case 'e':
			++chrs[1];
			break;

		case 'i':
			++chrs[2];
			break;

		case 'o':
			++chrs[3];
			break;

		case 'u':
			++chrs[4];
			break;

		default:
			break;

		}

	}

	for (int i = 0; i < VWLS; ++i)
	{
		for (int j = 0; j < chrs[i]; ++j)
			printf("-");
		printf("\n");

	}

}
