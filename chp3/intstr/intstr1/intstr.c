#include <stdio.h>
#include <string.h>

void itoa(int, char[]);

/* itoa: convert n to characters in s */

main()
{
	int n = -9.22337204e+18;
	char str[1000];

	itoa(++n, str);
	printf("%d\n%s\n", n, str);

	return(0);

}

void itoa(int n, char s[])
{
	int i, sgn;

	if ((sgn = n) < 0)
		n *= -1;
	
	i = 0;
	do
		s[i++] = (n % 10) + '0';
	while ((n = n / 10) > 0);

	if (sgn < 0)
		s[i++] = '-';
	s[i] = '\0';
	s = strrev(s);

}
