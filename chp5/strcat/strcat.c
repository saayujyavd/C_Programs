#include <stdio.h>

/* pointer version of the function strcat that was in chapter 2: mstrcat(s, t) copies the string t to the end of s. */

main()
{
	void mstrcat(char*, char*);
	void mstrcpy(char*, char*);
	char* ptr = "booboo";
	char* qtr = "baba";

	printf("ptr: %s\nqtr: %s\n", ptr, qtr);
	mstrcat(ptr, qtr);
	printf("ptr: %s\nqtr: %s\n", ptr, qtr);

	return(0);
}

void mstrcat(char* s, char* t)
{
	while (*s++ != '\0');
	s--;
	while (*s++ = *t++);
}
