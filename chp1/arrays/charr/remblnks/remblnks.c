#include <stdio.h>

#define MAXLEN 1000

int getline(char str[], int max);

/* remove trailing blanks & tabs from each line of input, and to delete entirely blank lines */

main()
{
	char line[MAXLEN], edtd[MAXLEN];
	int lnlen, i, k;

	k = 0;
	while ((lnlen = getline(line, MAXLEN)) <= MAXLEN)
	{
		i = lnlen;
		while ((line[i] == ' ' || line[i] == '\t'))
		{
			line[i] = '\0';
			--i;

		}

		if (i > 0)
		{
			for (int j = 0; j < lnlen; ++j, ++k)
				edtd[k] = line[j];

		}

	}
	printf("\n%s\n", edtd);

	return(0);

}

int getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < (lim - 1) && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
	{
		s[i] = c;
		++i;

	}
	s[i] = '\0';

	return(i);

}
