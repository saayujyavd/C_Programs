#include "ptrArrs.h"

readlines(char* lineptr[], int nlines)
{
	static int getline(char**);
	/* ... */
	int i, c;

	i = 0;
	while ((i < nlines) && ((c = getline(lineptr + i++)) != EOF));
	if (c != EOF) *(*(lineptr + (i - 1)) + c) = EOF;

	return(i);
}

static getline(char** line)
{
	if (!(*line)) *line = (char*)calloc(MAXCHRS, sizeof(char));

	int c, i;

	i = 0;
	while ((i < MAXCHRS) && ((c = getchar()) != '\n') && (c != EOF)) *(*line + i++) = c;
	if ((i == MAXCHRS) && (*(*line + (i - 1)) != '\n')) *(*line + (i - 1)) = '\n';
	if (c == EOF) return(EOF);

	return(i);
}
