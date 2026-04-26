#include <string.h>

/* qsort: sort v[left]...v[right] into increasing order */
void qsorts(char* v[], int left, int right)
{
	static void swap(char*[], int, int);
	/* ... */
	int i, last;

	if (left >= right) return;	/* do nothing if arr. contains fewer than 2 elements */

	swap(v, left, (left + right) / 2);
	last = left;

	for (i = left + 1; i <= right; ++i) if (strcmp(*(v + i), *(v + left)) < 0)
		swap(v, ++last, i);
	swap(v, left, last);
	qsorts(v, left, (last - 1));
	qsorts(v, (last + 1), right);
}

/* swap: interchange v[i] & v[j] */
static void swap(char* v[], int i, int j)
{
	char* temp;

	temp = *(v + i);
	*(v + i) = *(v + j);
	*(v + j) = temp;
}
