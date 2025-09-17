#include <ctype.h>
/* ... */
#include "calculator.h"

/* getop: get next oprtr. or numeric operand */
int getop(char s[])
{
    int getch(void);
    void ungetch(int);
    /* ... */
    int i, c;

    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    
    if(!isdigit(c) && c != '.') return(c);

    i = 0;
    if(isdigit(c))  /* collect integer part */
        while(isdigit(s[++i] = c = getch()))
            ;
    if(c == '.')    /* collect fractional part */
        while(isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';

    if(c != EOF) ungetch(c);
    return(NUMBER);
}

static char buf[MAX];   /* buffer for ungetch */
int bufp = 0;

getch(void) /* get a (possibly pushed back) character */
{
    char* cnvrt(char[]);
    /* ... */
    char str[MAX];
    static char cnv[MAX];
    static i = 0, icnv = 0;

    if(icnv++ == 0)
    {
        printf("Expression: ");
        gets_s(str, MAX);
        strcpy(cnv, cnvrt(str));
    }

    return((bufp > 0) ? buf[--bufp] : *(cnv + i++));
}

void ungetch(int c) /* push character back on input */
{
    if(bufp >= MAX) printf("ungetch: too many characters\n");
    else buf[bufp++] = c;
}
