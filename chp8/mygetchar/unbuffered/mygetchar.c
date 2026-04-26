#include <stdio.h>
#include <io.h>     /* _read() */

/*
 * Undefine getchar in case it is implemented as a macro in <stdio.h>
 * We use a renamed version my_getchar() to avoid redefining CRT getchar
 * which is undefined behaviour in MSVC even after #undef
 */
#ifdef getchar
#undef getchar
#endif

 /*
  * Unbuffered version of getchar() for Windows.
  * Reads stdin (fd 0) one character at a time via _read().
  * Cast to unsigned char prevents sign-extension of high bytes (e.g. 0xFF)
  * being mistaken for EOF (-1). char is signed by default on MSVC.
  */
int my_getchar(void)
{
    char c;
    return ((_read(0, &c, 1) == 1) ? (unsigned char)c : EOF);
}

int main(void)
{
    int c;
    while ((c = my_getchar()) != EOF)
        putchar(c);
    return 0;
}
