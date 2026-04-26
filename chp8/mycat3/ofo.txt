#include <stdio.h>

/* cat: concatenate files, version 3 */
main(int argc, char* argv[])
{
    FILE* fd;
    void filecopy(FILE*, FILE*);
    int myprintf(char*, ...);
    int myfclose(FILE*);
    FILE* myfopen(char*, char*);

    if(argc == 1)
        filecopy(stdin, stdout);
    else
    {
        while(--argc > 0)
        {
            if((fd = myfopen(*++argv, "r")) == 0)
            {
                myprintf("mycat: can't open %s\n", *argv);
                return(1);
            }
            else
            {
                filecopy(fd, stdout);
                myfclose(fd);
            }

        }
        
    }

    return(0);
}

/* filecopy: copy file ifp to file ofp */
void filecopy(FILE* ifp, FILE* ofp)
{
    int c;

    while((c = getc(ifp)) != EOF)
        putc(c, ofp);
}
