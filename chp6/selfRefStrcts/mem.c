#include "selfRefStrct.h"

/* talloc: make tnode */
struct tnode *talloc(void)
{
    return((struct tnode*)(malloc(sizeof(struct tnode))));
}

/* strdup: make a duplicate of word. */
char* strdup(char* word)
{
    char* dup;

    dup = NULL;
    dup = (char*)(malloc(strlen(word) + 1)); /* +1 for '\0 */
    if(dup != NULL)
        strcpy(dup, word);
    
    return(dup);
}
