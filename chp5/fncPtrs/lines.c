#include <stdio.h>
#include <string.h>

readlines(char* lineptr[], int nlines)
{
	static int getline(char*);
	char* line = NULL;
	int len;

	nlines = 0;
	while(getline(line) != EOF)
	{
		printf("%s\n", line);
		if (strlen(line) != 0)
			*lineptr[nlines++] = *line;
	}

	return(nlines);
}

void writelines(char* lineptr[], int nlines)
{
	for (int i = 0; i < nlines; i++)
		printf("%s\n", *lineptr++);
}

static getline(char* line)
{
	int i, c;

	i = 0;
	while ((c = getchar()) != EOF && (c != '\n'))
		line[i++] = c;
	if (c == '\n')
	{
		line[i++] = c;
		return(c);
	}

	return(EOF);
}
