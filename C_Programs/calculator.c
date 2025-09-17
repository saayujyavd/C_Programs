//
// calculator.c
//
//      Copyright (c) K&R Corporation. All rights reserved.
//
// The reverse Polish (postfix) calculator.
// 
// Developed by: Saayujya Vishwakumar Deshpande
//

#include "calculator.h"	/* for getop() & NUMBER */

/* reverse polish calculator */
double calculate()
{
	int getop(char[]);
	void push(double);
	double pop(void);
	/* ... */
	int type;
	double op2;
	char s[MAX];

	while(type = getop(s))
	{
		switch(type)
		{
		case NUMBER:
			push(atof(s));
			break;

		case '+':
			push(pop() + pop());
			break;
		
		case '*':
			push(pop() * pop());
			break;

		case '-':
			op2 = pop();
			push(pop() - op2);
			break;

		case '/':
			op2 = pop();
			if(op2 != 0.0) push(pop() / op2);
			else printf("err: zero divisor\n");
			break;

		case '(':
		case ')':
			break;

		default:
			printf("err: unknown command %s\n", s);
			break;
		}

	}

	return(pop());
}

static int sp = 0;		/* next free stack position */
static double val[MAX];	/* value stack */

/* push: push f onto value stack */
void push(double f)
{
	if(sp < MAX) val[sp++] = f;
	else printf("err: stack full, can't push %g\n", f);
}

/* pop: pop & return top value from stack */
double pop(void)
{
	if(sp > 0) return(val[--sp]);
	else
	{
		printf("err: stack empty\n");
		return(0.0);
	}

}
