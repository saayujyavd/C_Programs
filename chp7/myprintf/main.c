#define MAXCHRS 100

main()
{
    int myprintf(char*, ...);

    myprintf("hello, world!\n");
    myprintf("%d f s %c h %i h %o f o %x m\n", 23, 'j', 34, 710, 0Xabc, "s");

    return(0);
}
