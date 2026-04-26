#include <stdio.h>

void real(char[], char[]);
void escape(char[], char[]);

/*	convert characters like newline and tab into visible escape sequences like \n and \t
	as it copies the string t to s. Use a switch. */

main()
{
	char str[] = "evfmo\trvrn iohg\nrng hid\t\n\n\tfko nsrgv\t\tfsnvi\n";
	char rts[] = "evfmo\rvrn iohg/rng hid\//\fko nsrgv\\fsnvi/";
	char temp[1000];

	escape(temp, str);
	printf("%s\n", temp);
	real(temp, rts);
	printf("%s\n", temp);

	return(0);

}

void real(char s[], char t[])
{
	int c, i;

	i = 0;
	while ((c = t[i]) != '\0')
	{
		switch (c)
		{
		case '/':
			s[i] = '\n';
			break;

		case '\\':
			s[i] = '\t';
			break;

		default:
			s[i] = c;
			break;

		}
		++i;

	}

}

void escape(char s[], char t[])
{
	int c, i;

	i = 0;
	while ((c = t[i]) != '\0')
	{
		switch (c)
		{
		case '\n':
			s[i] = '/';
			break;

		case '\t':
			s[i] = '\\';
			break;

		default:
			s[i] = c;
			break;

		}
		++i;

	}

}
