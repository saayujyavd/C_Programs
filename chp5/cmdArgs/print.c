#include <stdio.h>

main(int argc, char* argv[])
{
    char* s;

    while (s = *++argv)
        printf("%s ", s);
    return(0);
}
