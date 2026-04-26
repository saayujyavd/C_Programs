#include <stdio.h>
#include <ctype.h>
#include <string.h>
/* ... */
#include "strctPtr.h"

#define MAXCHRS		100
#define NUMKEYS		sizeof(sizeof(keys) / sizeof(struct key))

main()
{
	int getword(char* word, int lim);
	struct key* binsrch(char* word, struct key* keyword, int len);
	struct key* keyword;
	int indx;
	char word[MAXCHRS];
	
	while (getword(word, MAXCHRS) != EOF)
		if (isalpha(*word) && ((keyword = binsrch(word, keys, NUMKEYS)) != NULL))
			keyword->count++;

	for (keyword = keys; keyword < keys + NUMKEYS; keyword++)
		printf("%s: %d\n", keyword->word, keyword->count);

	return(0);
}

getword(char* word, int lim)
{
	int c, i;

	while ((c = getchar()) == ' ')
		;
	word[0] = c;

	i = 1;
	while (((c = getchar()) != ' ') && (c != EOF) && (c != '\n'))
		word[i++] = c;
	word[i] = '\0';

	if (c == EOF)
		return(EOF);
	else
		return(i);
}

struct key* binsrch(char* word, struct key* keyword, int len)
{
	int condition;
	struct key* low;
	struct key* mid;
	struct key* high;

	low = keyword;
	high = &keyword[len];
	while (low <= high)
	{	
		mid = low + ((high - low) / 2);
		if ((condition = strcmp(word, mid->word)) > 0)
			low = mid + 1;
		else if (condition < 0)
			high = mid - 1;
		else
			return(mid);
	}

	return(NULL);
}
