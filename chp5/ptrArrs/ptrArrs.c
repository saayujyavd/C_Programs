#include "ptrArrs.h"

#define MAXLINES	5000	/* max #lines to be sorted */

/* sort input lines */
main()
{
	int readlines(char* [], int);
	void writelines(char* [], int), qsorts(char* [], int, int);
	static void frees(char* []);
	/* ... */
	int nlines;	/* no. of input lines read */
	char* lineptr[MAXLINES];

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
	{
		qsorts(lineptr, 0, (nlines - 1));
		writelines(lineptr, nlines);
	}
	else
	{
		fprintf(stderr, "err: input too big to sort\n");
		frees(lineptr);
		return(1);
	}

	frees(lineptr);
	return(0);
}

/* writelines: write output lines */
void writelines(char* lineptr[], int nlines)
{
	if (!lineptr) return;
	else printf("\n%d lines...\n", nlines);
	
	int i;

	i = 0;
	while (i < nlines) printf("%s\t\t", *(lineptr + i++));

	return;
}

static void frees(char* lines[])
{
	int i;

	i = 0;
	while (*(lines + i++));
	while (--i >= 0) free(*(lines + i));

	return;
}
