#include <stdio.h>

#define MAXLEN 1000

int mxln;
char line[MAXLEN], maxline[MAXLEN];

int getline(void);
void copy(void);

/* print longest input line; specialized (but inferior to previous) version */

main()
{
	int ln;
	int i;
	extern int mxln;
	extern char line[MAXLEN], maxline[MAXLEN];

	mxln = 0;
	while ((ln = getline()) > 0)
	{
		if (ln > mxln)
		{
			mxln = ln;
			copy();

		}

	}
	if (mxln > 0)
		printf("%s\n", maxline);

	return(0);

}

int getline(void)
{
	int c, i;
	extern char line[];

	i = 0;
	while ((c = getchar()) != EOF && c != '\n')
	{
		line[i] = c;
		++i;

	}
	if (c == '\n')
	{
		line[i] = c;
		++i;

	}
	line[i] = '\0';

	return(i);

}

void copy(void)
{
	int i;
	extern char line[], maxline[];

	i = 0;
	while ((maxline[i] = line[i]) != '\0')
		++i;

}
