#include <stdio.h>
#include <ctype.h>	/* for isspace(), isdigit() */

int getint(int* pn);

/* getint: get next integer from input into the pointer: pn */

main()
{
	int t = 0;
	int* p = &t;
	
	getint(p);
	printf("%d\n", *p);

	return(0);
}

int getint(int* pn)
{
	int c, sgn;

	while (isspace(c = getchar()))	/* skip white space */
		;

	if (!isdigit(c) && c != EOF && c != '+' && c != '-')	/* it's not a number */
		return(0);

	sgn = ((c == '-') ? -1 : 1);
	if (c == '+' || c == '-')
		c = getchar();

	for (*pn = 0; isdigit(c); c = getchar())
		*pn = (10 * (*pn)) + (c - '0');
	*pn = sgn * (*pn);
	
	return(c);
}
