#include <stdio.h>

#define BLANK ' '
#define TAB '\t'
#define RETURN '\n'

/* count digits, white spaces, others */

main()
{
	int blanks, others;
	int digits[10];
	int c;

	blanks = others = 0;

	for (int i = 0; i < 10; ++i)
		digits[i] = 0;

	while ((c = getchar()) != EOF)
	{
		if (c >= '0' && c <= '9')
			++digits[c - '0'];
		else if (c == BLANK || c == RETURN || c == TAB)
			++blanks;
		else
			++others;

	}

	printf("digits =");
	for (int i = 0; i < 10; ++i)
		printf(" %d", digits[i]);
	printf(", white spaces = %d, others = %d\n", blanks, others);

}
