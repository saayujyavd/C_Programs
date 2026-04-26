#include "mygetchar.h"

int my_getchar(void)
{
    static char  buf[BUFSIZ];
    static char* bufp = buf;
    static int   remaining = 0;

    /* Refill buffer when empty */
    if (remaining <= 0)
    {
        remaining = _read(0, buf, sizeof(buf));   /* fd 0 = stdin */
        bufp = buf;

        if (remaining < 0)          /* read error */
            return EOF;

        if (remaining == 0)         /* EOF / Ctrl+Z on Windows */
            return EOF;
    }

    remaining--;
    return (unsigned char)*bufp++;  /* cast prevents sign-extension of high bytes */
}
