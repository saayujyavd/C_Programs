#include "selfRefStrct.h"

#define MAXCHRS 100

/* word frequency count */
main()
{
    struct tnode* addtree(struct tnode*, char*);
    void treeprint(struct tnode*);
    int getword(char*, int);
    /* ... */
    struct tnode* root;
    char word[MAXCHRS];

    root = NULL;
    while(getword(word, MAXCHRS) != EOF)
        if(isalpha(*word))
            root = addtree(root, word);
    
    treeprint(root);
    return(0);
}

getword(char* word, int lim)
{
	int c, i;

	while ((c = getchar()) == ' ')
		;
	word[0] = c;

	i = 1;
	while (((c = getchar()) != ' ') && (c != EOF) && (c != '\n'))
		word[i++] = c;
	word[i] = '\0';

	if (c == EOF)
		return(EOF);
	else
		return(i);
}
