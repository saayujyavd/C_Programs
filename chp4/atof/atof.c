#include <stdio.h>
#include <string.h>
#include <math.h>

#ifdef atof
#undef atof
#endif

double atof(char*);

/* atof: convert string s to double */

main()
{
	char str[] = "123.45e-6";
	printf("%lf\n", atof(str));

	return(0);

}

double atof(char s[])
{
	int present(char, char[]);

	int i, eind, exp, len, sgn = 1;
	double n = 0.0F;

	i = 0;
	while ((i < ((len = strlen(s)) - (eind = present('e', s)))) && (s[i] != '.'))
		n = (10.0F * n) + (s[i++] - '0');

	i = (len - eind);
	if (s[i] == '-')
		sgn = -1;

	exp = 0;
	while (i < (len - 1))
		exp = (10 * exp) + (s[++i] - '0');

	return(n * pow(10, exp * sgn));
}
