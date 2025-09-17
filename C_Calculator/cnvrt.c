//
// cnvrt.c
//
//      Copyright (c) K&R Corporation. All rights reserved.
//
// The reverse Polish (postfix) calculator(integer only) cnvrt.c sub-file.
// 
// Developed by: Saayujya Vishwakumar Deshpande
//

/* header file/s */
#include <stdlib.h>	/* for calloc() */
#include <string.h>	/* for string rel. func/s. */

/* macro substitution/s */
#define MAXCHRS	255			/* max. chars in arrays */

/* global variable/s */
static char* pfx = NULL;

/* cnvrt: convert infix expression to postfix expression */
char* cnvrt(char expr[])
{
	static int isop(char), hiprec(char oprtr), oprbuff(char);
	static void empobuf(void), getop(void);
	/* ... */
	char c, tmp[MAXCHRS];
	int i, j;

	if ((pfx == NULL) && ((pfx = (char*)calloc(MAXCHRS, sizeof(char))) == NULL)) return(NULL);

	j = 0;
	i = strlen(expr);
	while ((c = *(expr + j)) && (j++ < i))
	{
		if (!isop(c))
		{
			*tmp = c; *(tmp + 1) = '\0';
			strcat(pfx, tmp);
			continue;
		}
		switch (hiprec(c))
		{
		case 1:
			break;
		case 2:
			empobuf();
			break;
		case 3:
			getop();
			break;
		default:
			break;
		}

		oprbuff(c);
	}
	empobuf();

	*tmp = '\0';
	return(strcat(pfx, tmp));
}

/* isop: check if a char is an operator */
isop(char oprtr)
{
	switch (oprtr)
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '(':
		return(1);

	default:
		return(0);
	}

}

static char obuff[MAXCHRS];	/* operator buffer */
static int oidx = 0;		/* current operator index */

/* hiprec: check if char has higher precedence than the prev. char in obuff */
static hiprec(char oprtr)
{
	void getop(void);
	/* ... */
	char c;

	if (oidx > 0)
	{
		if((c = *(obuff + oidx - 1) == '('))														return(1); 
		else if (((c = *(obuff + oidx - 1)) == '/' || c == '*') && (oprtr == '+' || oprtr == '-'))	return(2);
		else if ((c == '/' || c == '*') && (oprtr == '/' || oprtr == '*'))							return(3);
		else if ((c == '+' || c == '-') && (oprtr == '+' || oprtr == '-'))							return(3);
	}

	return(0);
}

/* oprbuff: add operator to obuff */
static oprbuff(char o)
{
	if (oidx == MAXCHRS)
		return(0);		// obuff full

	*(obuff + oidx++) = o;
	return(oidx);
}

/* getop: get operator from obuff */
static void getop(void)
{
	char tmp[MAXCHRS];

	*tmp = *(obuff + --oidx); *(tmp + 1) = '\0';
	strcat(pfx, tmp);
}

/* empobuf: empty to obuff */
static void empobuf(void)
{
	char tmp[MAXCHRS];

	while (oidx > 0)
	{
		*tmp = *(obuff + --oidx); *(tmp + 1) = '\0';
		strcat(pfx, tmp);
	}

}
