#include <stdio.h>

/* cat: concatenate 2 files version 2 */
main(int argc, char* argv[])
{
    void filecopy(FILE*, FILE*);
    FILE* fp;
    char* prog;

    prog = argv[0];
    if(argc == 1)
        filecopy(stdin, stdout);
    else
    {
        if((fp = fopen(argv[1], "r")) == NULL)
        {
            fprintf(stderr, "%s: can't open %s\n", prog, argv[1]);
            exit(1);
        }
        else
        {
            filecopy(fp, stdout);
            fclose(fp);
        }

    }
    if(ferror(stdout))
    {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }

    exit(0);
}

/* filecopy: copy file ifp to file ofp */
void filecopy(FILE* ifp, FILE* ofp)
{
    int c;

    while((c = getc(ifp)) != EOF)
        putc(c, ofp);

}
