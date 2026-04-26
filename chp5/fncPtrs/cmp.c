#include <stdio.h>
#include <stdlib.h>	/* for atof() */

int numcmp(char* s1, char* s2)
{
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);

	if (v1 > v2)
		return(1);
	else if (v1 == v2)
		return(0);
	else
		return(-1);
}

int strcmp(char* s1, char* s2)
{
	printf("instrcmp\n");
	while (*s1 == *s2++)
	{
		if (*s1++ == '\0')
			return(0);
	}
	printf("outstrcmp\n");
	return(*s1 - *--s2);
}
