#include <stdio.h>
#include <string.h>

void squeeze(char str1[], char str2[]);

/* delete each character in s1 that matches any character in s2 */

main()
{
	char str1[] = "I am a string!", str2[] = "string";

	squeeze(str1, str2);
	printf("%s\n", str1);

	return(0);

}

void squeeze(char s1[], char s2[])
{
	int i, j;
	int s1len;

	s1len = strlen(s1);
	i = 0;
	while (s2[i] != '\0')
	{
		j = 0;
		while (s1[j] != '\0')
		{
			if(s1[j] == s2[i])
				s1[j] = '_';
			++j;

		}
		++i;

	}

}
