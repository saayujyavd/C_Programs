#include <stdio.h>

#define MAXLEN 1000
#define LNGTHN 20
/* LNGTHN: longer than */

getline(char str[], int max);
/* default return-type is 'int' */

/* print all input lines that are longer than value of 'LNGTHN' */

main()
{
	char line[MAXLEN], grtr[MAXLEN];
	int lnlen, lngengh;
	int i, j;

	lngengh = i = j = 0;

	while ((lnlen = getline(line, MAXLEN)) > 0)
	{
		if (lnlen > LNGTHN)
		{
			for(j = 0; j < (lnlen); ++j)
			{
				grtr[i] = line[j];
				++i;

			}

		}

	}
	printf("%s\n", grtr);

	return(0);

}

/* again, default return-type of getline is 'int' */
getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < (lim - 1) && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
	{
		s[i] = c;
		++i;

	}

	return(i);

}
