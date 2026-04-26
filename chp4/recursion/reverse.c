#include <stdio.h>
#include <string.h>

void reverse(char[], int, int);

/* a recursive version of the function reverse(s), which reverses the string s in place */

main()
{
	char str[] = "my name is anthony gonzalvis";

	printf("%s\n", str);
	reverse(str, 0, strlen(str) - 1);
	printf("%s\n", str);

	return(0);

}

void reverse(char s[], int i, int j)
{
	int t = strlen(s) - 1, k = t / 2;
	char temp;

	if (i <= k && j >= k)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;

		reverse(s, ++i, --j);

	}

}
