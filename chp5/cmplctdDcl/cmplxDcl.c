#include <stdio.h>
#include <string.h>

enum { NAME, PARENS, BRACKETS };

#define MAXCHAR	127

typedef int tokentype;

tokentype type;
char token[MAXCHAR], output[MAXCHAR];

main()
{

	return(0);
}

/* dcl: parse a declarator */
void dcl(void)
{
	tokentype gettoken(void);
	size_t num_stars;

	for (num_stars = 0; gettoken() == '*'; ++num_stars); /* count *'s */

	while (num_stars-- > 0)
		strcat(output, " ptr to");
}

/* return next token */
tokentype gettoken()
{
	int c;
	char* p = token;

	while ((c = getchar()) == ' ' || (c == '\t'))
		;

	if (c == '(')
	{
		if (getchar() == ')')
		{
			strcpy(token, '()');
			return(type = PARENS);
		}
		else return(type = '(');
	}


}
