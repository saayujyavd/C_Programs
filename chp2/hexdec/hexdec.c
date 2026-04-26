#include <stdio.h>

int htoi(char str[]);

/* convert a string of hexadecimal digits into its equivalent integer value */

main()
{
	char str[] = { '0', 'x', '1', 'g', '2', '\0' };
	int istr;

	istr = htoi(str);
	printf("%d\n", istr);

	return(0);

}

int htoi(char s[])
{
	int i, n;

	n = i = 0;
	while (s[i] != '\0')
	{
		if ('0' <= s[i] && s[i] <= '9')
			n = 10 * n + (s[i] - '0');
		else if ('a' <= s[i] && s[i] <= 'f')
			n = 10 * n + (s[i]);
		else if ('A' <= s[i] && s[i] <= 'F')
			n = 10 * n + (s[i]);
		
		++i;

	}

	return(n);

}
