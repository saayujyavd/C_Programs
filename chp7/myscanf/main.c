#include <stdio.h>

main()
{
    int myscanf(char*, ...);
    /* ... */
    int n, o;

    myscanf("%d %i", &n, &o);
    printf("%d %d", n, o);
    
    return(0);
}
