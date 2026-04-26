#include <stdio.h>

#define MAXLEN 1000
#define RETURN '\n'

int getline(char[], int);
void copy(char from[], char to[]);

/* print longest input line */

main()
{
	char line[MAXLEN], maxline[MAXLEN];
	int ln, mxln;
	int i;

	ln = mxln = 0;

	while ((ln = getline(line, MAXLEN)) > 0)
	{
		if (ln > mxln)
		{
			mxln = ln;
			copy(line, maxline);

		}

	}
	if (mxln > 0)
		printf("%s\n", maxline);

	return(0);

}

int getline(char s[], int len)
{
	int c, i;

	i = 0;
	while ((c = getchar()) != EOF && c != RETURN)
	{
		s[i] = c;
		++i;

	}
	if (c == RETURN)
	{
		s[i] = c;
		++i;

	}
	s[i] = '\0';

	return(i);

}

void copy(char from[], char to[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;

}
