#include <stdio.h>
#include <string.h>

void itob(int n, char str[], unsigned base);

enum nmsys
{
	BIN = 2, TRI, QUA, PEN, SEC, SEP, OCT, NAN, DEC, HEX = 16

};

/*	convert the integer n into a base b character representation in the string s.
	in particular itob(n, s, 16) formats n as a hexadecimal integer in s. */

main()
{
	int n = -11911;
	char s[1000];

	itob(n, s, OCT);
	printf("%s\n", s);

	return(0);

}

void itob(int n, char s[], unsigned b)
{
	int d, i, sgn;

	if ((sgn = n) < 0)
		n *= -1;

	i = 0;
	switch (b)
	{
	case BIN:
		do
		{
			if ((0 <= (d = n % 10)) && (d < BIN))
				s[i++] = d + '0';
			else
				s[i++] = '0';

		}
		while ((n /= 10) > 0);

		break;

	case OCT:
		do
		{
			if ((0 <= (d = n % 10)) && (d < OCT))
				s[i++] = d + '0';
			else
				s[i++] = '0';

		} 
		while ((n /= 10) > 0);

		break;

	case DEC: case HEX:
		do
		{
			if ((0 <= (d = n % 10)) && (d < DEC))
				s[i++] = d + '0';
			else
				s[i++] = '0';

		} while ((n /= 10) > 0);

		break;

	default:
		break;

	}

	if (sgn < 0)
		s[i++] = '-';
	s[i] = '\0';
	s = strrev(s);

}
