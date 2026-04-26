#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct tnode
{
	char* word;	/* pts. to txt. */
	int count;	/* no. of occurrences */
	struct tnode* left;	/* left child */
	struct tnode* right;/* right child */
};
