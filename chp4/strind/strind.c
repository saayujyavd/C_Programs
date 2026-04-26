#include <stdio.h>
#include <string.h>

int strrindex(char str[], char[]);

main()
{
	char str[] = "I am a string", t[] = "string";
	
	printf("%d\n", strrindex(str, t));

	return(0);

}

int strrindex(char s[], char t[])
{
	int i, j, k, l;

	for (i = strlen(s) - 1; i >= 0; --i)
	{
		for (j = i, k = (l = (strlen(t) - 1)); ((k >= 0) && (s[j] == t[k])); --j, --k)
			;
		if (k < l)
			return(i);

	}
	return(-1);

}
