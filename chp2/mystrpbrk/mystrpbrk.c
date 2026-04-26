#include <stdio.h>

int any(char str1[], char str2[]); /* acts similar to strpbrk */

/* return the first location in the string s1 where any character from the string s2 occurs, or -1 if s1 contains no characters from s2 */

main()
{
	char str1[] = "I am a string!", str2[] = "string";
	int loc;

	loc = any(str1, str2);
	printf("%d\n", loc);

	return(0);

}

int any(char s1[], char s2[])
{
	int i, j;
	int occrs;

	i = 0;
	while (s2[i] != '\0')
	{
		j = 0;
		while (s1[j] != '\0')
		{
			if (s1[j] == s2[i])
				return(++j);
			++j;

		}
		++i;

	}

	return(-1);

}
