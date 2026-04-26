#include <stdarg.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdlib.h>     /* strtol(), strtoul(), strtod() */
#include <string.h>     /* strlen()                      */

static int remblk(void);

int myscanf(const char* fmt, ...)
{
    va_list      ap;
    const char* ptr;
    int          c;
    int          chrs = 0;          /* count of format chars processed  */
    int          assigned = 0;      /* count of successful assignments  */
    char         numbuf[64];        /* buffer for building number str   */
    int          nlen;

    va_start(ap, fmt);

    for (ptr = fmt; *ptr; ptr++, chrs++)
    {
        /* ------------------------------------------------------------ */
        /* Handle escape sequences in the format string                  */
        /* ------------------------------------------------------------ */
        if (*ptr == '\\')
        {
            ptr++;
            switch (*ptr)
            {
            case 'n':  c = getchar(); if (c != '\n') ungetc(c, stdin); break;
            case 't':  c = getchar(); if (c != '\t') ungetc(c, stdin); break;
            case 'r':  c = getchar(); if (c != '\r') ungetc(c, stdin); break;
            case 'v':  c = getchar(); if (c != '\v') ungetc(c, stdin); break;
            case 'f':  c = getchar(); if (c != '\f') ungetc(c, stdin); break;
            case 'b':  c = getchar(); if (c != '\b') ungetc(c, stdin); break;
            case 'a':  c = getchar(); if (c != '\a') ungetc(c, stdin); break;
            case '\\': c = getchar(); if (c != '\\') ungetc(c, stdin); break;
            default:   break;
            }
            continue;
        }

        /* ------------------------------------------------------------ */
        /* Handle format specifiers                                       */
        /* ------------------------------------------------------------ */
        if (*ptr == '%')
        {
            ptr++;

            /* %% — match a literal '%' in input */
            if (*ptr == '%')
            {
                c = remblk();
                if (c != '%')
                    ungetc(c, stdin);
                continue;
            }

            switch (*ptr)
            {
                /* ---- Signed decimal integer ---- */
            case 'd':
            {
                int* tmp = va_arg(ap, int*);
                *tmp = 0;
                nlen = 0;
                c = remblk();
                if (c == '-' || c == '+')        /* handle sign */
                {
                    numbuf[nlen++] = (char)c;
                    c = getchar();
                }
                while (isdigit(c) && nlen < 63)
                {
                    numbuf[nlen++] = (char)c;
                    c = getchar();
                }
                numbuf[nlen] = '\0';
                ungetc(c, stdin);
                if (nlen > 0)
                {
                    *tmp = (int)strtol(numbuf, NULL, 10);
                    assigned++;
                }
                break;
            }

            /* ---- Signed integer: decimal, octal (0), hex (0x/0X) ---- */
            case 'i':
            {
                int* tmp = va_arg(ap, int*);
                *tmp = 0;
                nlen = 0;
                c = remblk();
                if (c == '-' || c == '+')
                {
                    numbuf[nlen++] = (char)c;
                    c = getchar();
                }
                /* Collect 0x/0X prefix or leading 0 for octal */
                if (c == '0')
                {
                    numbuf[nlen++] = (char)c;
                    c = getchar();
                    if (c == 'x' || c == 'X')
                    {
                        numbuf[nlen++] = (char)c;
                        c = getchar();
                        while (isxdigit(c) && nlen < 63)
                        {
                            numbuf[nlen++] = (char)c;
                            c = getchar();
                        }
                    }
                    else
                    {
                        while (c >= '0' && c <= '7' && nlen < 63)
                        {
                            numbuf[nlen++] = (char)c;
                            c = getchar();
                        }
                    }
                }
                else
                {
                    while (isdigit(c) && nlen < 63)
                    {
                        numbuf[nlen++] = (char)c;
                        c = getchar();
                    }
                }
                numbuf[nlen] = '\0';
                ungetc(c, stdin);
                if (nlen > 0)
                {
                    *tmp = (int)strtol(numbuf, NULL, 0);  /* base 0 = auto-detect */
                    assigned++;
                }
                break;
            }

            /* ---- Unsigned decimal integer ---- */
            case 'u':
            {
                unsigned int* tmp = va_arg(ap, unsigned int*);
                *tmp = 0;
                nlen = 0;
                c = remblk();
                while (isdigit(c) && nlen < 63)
                {
                    numbuf[nlen++] = (char)c;
                    c = getchar();
                }
                numbuf[nlen] = '\0';
                ungetc(c, stdin);
                if (nlen > 0)
                {
                    *tmp = (unsigned int)strtoul(numbuf, NULL, 10);
                    assigned++;
                }
                break;
            }

            /* ---- Octal integer ---- */
            case 'o':
            {
                unsigned int* tmp = va_arg(ap, unsigned int*);
                *tmp = 0;
                nlen = 0;
                c = remblk();
                while (c >= '0' && c <= '7' && nlen < 63)
                {
                    numbuf[nlen++] = (char)c;
                    c = getchar();
                }
                numbuf[nlen] = '\0';
                ungetc(c, stdin);
                if (nlen > 0)
                {
                    *tmp = (unsigned int)strtoul(numbuf, NULL, 8);
                    assigned++;
                }
                break;
            }

            /* ---- Hex integer (lowercase and uppercase) ---- */
            case 'x':
            case 'X':
            {
                unsigned int* tmp = va_arg(ap, unsigned int*);
                *tmp = 0;
                nlen = 0;
                c = remblk();
                /* Skip optional 0x / 0X prefix */
                if (c == '0')
                {
                    numbuf[nlen++] = (char)c;
                    c = getchar();
                    if (c == 'x' || c == 'X')
                    {
                        numbuf[nlen++] = (char)c;
                        c = getchar();
                    }
                }
                while (isxdigit(c) && nlen < 63)
                {
                    numbuf[nlen++] = (char)c;
                    c = getchar();
                }
                numbuf[nlen] = '\0';
                ungetc(c, stdin);
                if (nlen > 0)
                {
                    *tmp = (unsigned int)strtoul(numbuf, NULL, 16);
                    assigned++;
                }
                break;
            }

            /* ---- Float: %f, %e, %g ---- */
            case 'f':
            case 'e':
            case 'E':
            case 'g':
            case 'G':
            {
                float* tmp = va_arg(ap, float*);
                *tmp = 0.0f;
                nlen = 0;
                c = remblk();
                if (c == '-' || c == '+')
                {
                    numbuf[nlen++] = (char)c;
                    c = getchar();
                }
                /* Integer part */
                while (isdigit(c) && nlen < 63)
                {
                    numbuf[nlen++] = (char)c;
                    c = getchar();
                }
                /* Decimal point */
                if (c == '.')
                {
                    numbuf[nlen++] = (char)c;
                    c = getchar();
                    while (isdigit(c) && nlen < 63)
                    {
                        numbuf[nlen++] = (char)c;
                        c = getchar();
                    }
                }
                /* Exponent */
                if ((c == 'e' || c == 'E') && nlen < 62)
                {
                    numbuf[nlen++] = (char)c;
                    c = getchar();
                    if (c == '+' || c == '-')
                    {
                        numbuf[nlen++] = (char)c;
                        c = getchar();
                    }
                    while (isdigit(c) && nlen < 63)
                    {
                        numbuf[nlen++] = (char)c;
                        c = getchar();
                    }
                }
                numbuf[nlen] = '\0';
                ungetc(c, stdin);
                if (nlen > 0)
                {
                    *tmp = (float)strtod(numbuf, NULL);
                    assigned++;
                }
                break;
            }

            /* ---- Single character ---- */
            case 'c':
            {
                char* tmp = va_arg(ap, char*);
                c = getchar();              /* no whitespace skip for %c */
                if (c != EOF)
                {
                    *tmp = (char)c;
                    assigned++;
                }
                break;
            }

            /* ---- String (stops at whitespace) ---- */
            case 's':
            {
                char* tmp = va_arg(ap, char*);
                c = remblk();
                while (c != EOF && !isspace(c))
                {
                    *tmp++ = (char)c;
                    c = getchar();
                }
                *tmp = '\0';
                ungetc(c, stdin);
                assigned++;
                break;
            }

            /* ---- Pointer ---- */
            case 'p':
            {
                void** tmp = va_arg(ap, void**);
                nlen = 0;
                c = remblk();
                /* Skip optional 0x / 0X prefix */
                if (c == '0')
                {
                    numbuf[nlen++] = (char)c;
                    c = getchar();
                    if (c == 'x' || c == 'X')
                    {
                        numbuf[nlen++] = (char)c;
                        c = getchar();
                    }
                }
                while (isxdigit(c) && nlen < 63)
                {
                    numbuf[nlen++] = (char)c;
                    c = getchar();
                }
                numbuf[nlen] = '\0';
                ungetc(c, stdin);
                if (nlen > 0)
                {
                    *tmp = (void*)(size_t)strtoul(numbuf, NULL, 16);
                    assigned++;
                }
                break;
            }

            default:
                break;
            }
        }
        /* ------------------------------------------------------------ */
        /* Plain character in format — consume matching char from input  */
        /* ------------------------------------------------------------ */
        else
        {
            c = getchar();
            if (c != *ptr)
                ungetc(c, stdin);   /* put it back if no match */
        }
    }

    va_end(ap);
    return assigned;    /* like real scanf: return number of successful assignments */
}

/* ------------------------------------------------------------------ */
/* remblk: skip all whitespace and return first non-whitespace char    */
/* ------------------------------------------------------------------ */
static int remblk(void)
{
    int c;
    while (isspace(c = getchar()))  /* isspace covers ' ' \t \n \r \v \f */
        ;
    return c;
}
