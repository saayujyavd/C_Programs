#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHRS 100

static int stremp(char*);

/* myprintf: minimal printf with variable arg. list */
myprintf(char* fmt, ...)
{
    static void strput(char*);
    /* ... */
    va_list ap; /* pts. to each unnamed arg. in turn */
    char* ptr;
    char sval[MAXCHRS];
    int chrs = 0;

    if(stremp(fmt))
        return(chrs);

    va_start(ap, fmt);  /* make ap pt. to first unnamed arg. */
    for(ptr = fmt, chrs = 0; *ptr; ptr++, chrs++)
    {
        if(*ptr != '%')
        {
            putchar(*ptr);
            continue;
        }
        switch(*++ptr)
        {
            case 'd':
            case 'i':
                strput(itoa(va_arg(ap, int), sval, 10));
                break;

            case 'o':
                strput(itoa(va_arg(ap, int), sval, 8));
                break;

            case 'x':
            case 'X':
                strput(itoa(va_arg(ap, int), sval, 16));
                break;

            case 'c':
                putchar(va_arg(ap, char));
                break;

            case 's':
                strput(va_arg(ap, char*));
                break;

            default:
                putchar(*ptr);
                break;

        }
    }
    va_end(ap); /* clean-up when done */

    return(chrs);
}

static void strput(char* str)
{
    if(!stremp(str))
        for(int i = 0; i < strlen(str); i++)
            putchar(str[i]);
}

static stremp(char* str)
{
    if(str == NULL || strlen(str) == 0)
        return(1);
    else
        return(0);
}
