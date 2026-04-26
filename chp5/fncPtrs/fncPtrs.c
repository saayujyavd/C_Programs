#include <stdio.h>

#define MAXLINES	5000	/* max lines to be sorted */	

char* lineptr[MAXLINES];	/* ptrs. to txt. lines */

int readlines(char* lineptr[], int nlines);
void writelines(char* lineptr[], int nlines);
void qsort(void* lineptr[], int left, int right, int (*cmp)(void*, void*));
int strcmp(char*, char*);
int numcmp(char*, char*);

/* sort input lines */

main(int argc, char* argv[])
{
	int nlines;	/* no. of input lines */
	int srtNmrc = 0;	/* 1 if numeric sort */

	if (argc > 1)
	{
		if (*argv[1] == '-n')
			srtNmrc = 1;
		if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
		{
			qsort((void**)(lineptr), 0, nlines - 1, (int (*)(void*, void*))(srtNmrc ? numcmp : strcmp));
			writelines(lineptr, nlines);
		}
		else
			printf("input too big to sort\n");
	}
	else
		printf("Usage: fncPtrs.exe <arguments>\n");

	return(0);
}

void qsort(void* v[], int left, int right, int (*cmp)(void*, void*))
{
	int i, last;
	void swap(void* v[], int, int);

	if (left >= right)	/* do nothing if array contains */
		return;			/* fewer than two elements */

	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
	{
		if ((*cmp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
		swap(v, left, last);
	}
	qsort(v, left, last, cmp);
	qsort(v, last + 1, right, cmp);

}

static void swap(void* v[], int left, int right)
{
	void* tmp;

	tmp = v[left];
	v[left] = v[right];
	v[right] = tmp;

}
