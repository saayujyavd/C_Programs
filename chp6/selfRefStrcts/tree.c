#include "selfRefStrct.h"

/* addtree: add a node with word, at or below ptr. */
struct tnode* addtree(struct tnode* ptr, char* word)
{
    struct tnode* talloc(void);
    char* strdup(char*);
    int condition;

    if(ptr == NULL)
    {
        ptr = talloc();
        ptr->word = strdup(word);
        ptr->count = 1;
        ptr->left = NULL;
        ptr->right = NULL;
    }
    else if((condition = strcmp(word, ptr->word)) == 0)
        ptr->count++;
    else if(condition > 0)
        ptr->right = addtree(ptr->right, word);
    else
        ptr->left = addtree(ptr->left, word);

    return(ptr);
}

/* treeprint: in-order print of tree ptr. */
void treeprint(struct tnode* root)
{
    if(root != NULL)
    {
        treeprint(root->left);
        printf("%s: %d\n", root->word, root->count);
        treeprint(root->right);
    }
    
}
