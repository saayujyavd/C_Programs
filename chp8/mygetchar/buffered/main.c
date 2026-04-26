#include "mygetchar.h"

int main(void)
{
    int c;
    while ((c = my_getchar()) != EOF)
        putchar(c);
    return 0;
}
