#include <stdio.h>
#include <ctype.h>
#include <string.h>
/* ... */
#include "strctArr.h"

#define MAXCHRS		100
#define NUMKEYS		sizeof(sizeof(keys) / sizeof(struct key))

main()
{
	int getword(char* word, int lim);
	int binsrch(char* word, struct key* keyword, int len);
	int wrdlen, indx;
	char word[MAXCHRS];
	
	while ((wrdlen = getword(word, MAXCHRS)) != EOF)
		if (isalpha(*word) && ((indx = binsrch(word, keys, NUMKEYS)) >= 0))
			keys[indx].count++;

	for (indx = 0; indx < NUMKEYS; indx++)
		printf("%s: %d\n", keys[indx].word, keys[indx].count);

	return(0);
}

getword(char* word, int lim)
{
	int c, i;

	while ((c = getchar()) == ' ')
		;
	word[0] = c;

	i = 0;
	while (((c = getchar()) != ' ') && (c != EOF) && (c != '\n'))
		word[++i] = c;
	word[++i] = '\0';

	if (c == EOF)
		return(c);
	else
		return(i);
}

binsrch(char* word, struct key* keyword, int len)
{
	int condition;
	int low, mid, high;

	low = 0;
	high = len - 1;
	while (low <= high)
	{	
		mid = (low + high) / 2;
		if ((condition = strcmp(word, keyword[mid].word)) > 0)
			low = mid + 1;
		else if (condition < 0)
			high = mid - 1;
		else
			return(mid);
	}

	return(-1);
}
