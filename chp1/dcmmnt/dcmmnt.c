#include <stdio.h>

int chrock(char opn, char cls);
int strock(char str[]);
int equals(char first[], char second[]);

/* remove all comments from a C program */

main()
{	
	if (strock("/*"))
		printf("\nCorrect comment/s!\n");
	else
		printf("\nNo comment/s! or invalid comment/s!\n");
	/*
	if (chrock('{', '}'))
		printf("\nCorrect opening-closing: {, }\n");
	else
		printf("\nWrong or no opening-closing: {, }\n");
	*/
	return(0);

}

int chrock(char op, char cl)
{
	int c;
	int in, out;

	in = 0;
	out = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == op)
			in = 1;
		if ((c = getchar()) == cl)
			out = 1;

	}

	if (in == 1 && out == 1)
		return(1);
	else
		return(0);

}

int strock(char s[])
{
	int c;
	int in, out;

	in = 0;
	out = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == s[0] && (c = getchar()) == s[1])
			in = 1;
		if ((c = getchar()) == s[1] && (c = getchar()) == s[0])
			out = 1;

	}

	if (in == 1 && out == 1)
		return(1);
	else
		return(0);

}

int equals(char f[], char s[])
{
	int i;

	i = 0;
	while (f[i] != '\0')
	{
		if (f[i] != s[i])
			return(0);
		else
			++i;

	}

	return(1);

}
