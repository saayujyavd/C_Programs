#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHRS 100
#define MAXLINE 100

main(int argc, char* argv[])
{
    static void prnts(char**, int);
    int fileCmp(char**, FILE*, FILE*);
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
            if(fileCmp(diff, stdin, ifo))
                prnts(diff, 2);    /* print lines in diff */
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
            if(fileCmp(diff, ifo, ift)) {
                printf("%s\n%s\n", diff[0], diff[1]);
                // prnts(diff, 2);
            }
            else
                printf("Both files have same lines\n");

        }

    }

    return(0);
}

static void prnts(char** str, int len)
{
    int i = 0;
    while(i < len) {
        printf("%s\n", *(str + i));
        i++;
    }
}

int fileCmp(char** pstr, FILE* pfo, FILE* pft)
{
    char line1[MAXCHRS], line2[MAXCHRS];
   
    while((fgets(line1, MAXLINE, pfo) != NULL) && (fgets(line2, MAXLINE, pft) != NULL))
    {
        if(strcmp(line1, line2) != 0)
        {
            strcpy(*pstr, line1);
            strcpy(*(pstr + 1), line2);
            
            return(1);
        }
        
    }

    return(0);
}
