#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHRS 100
#define MAXLINE 100

main(int argc, char* argv[])
{
    static void prnts(char***);
    int fileCmp(char***, FILE*, FILE*);
    char** diff;
    FILE* ifo, *ift;

    diff = (char**)malloc(sizeof(char*) * 2);
    for(int i = 0; i < 2; i++)
        diff[i] = (char*)malloc(sizeof(char) * MAXCHRS);

    if(argc < 2)
    {
        printf("Usage: fileCmp.exe <filename 1> <filename 2>\n");
        exit(1);
    }
    else if(argc == 2)
    {
        if((ifo = fopen(argv[1], "r")) != NULL)
        {
            if(fileCmp(&diff, stdin, ifo))
                prnts(&diff);    /* print lines in diff */
            else
                printf("Both files have same lines\n");

        }
        else
        {
            fprintf(stderr, "%s: error in %s\n", argv[0], argv[1]);
            exit(3);
        }

    }
    else
    {
        if(((ifo = fopen(argv[1], "r")) != NULL) && ((ift = fopen(argv[2], "r")) != NULL))
        {
            if(fileCmp(&diff, ifo, ift))
                prnts(&diff);
            else
                printf("Both files have same lines\n");

        }

    }

    return(0);
}

static void prnts(char*** c)
{
    while(**c)
        printf("%s\n", **c++);
}

int fileCmp(char*** diff, FILE* pfo, FILE* pft)
{
    char lineo[MAXCHRS], linet[MAXCHRS];
   
    while((fgets(lineo, MAXLINE, pfo) != NULL) && (fgets(linet, MAXLINE, pft) != NULL))
    {
        if(strcmp(lineo, linet) != 0)
        {
            *diff[0] = lineo;
            *diff[1] = linet;
            
            return(1);
        }

    }

    return(0);
}
