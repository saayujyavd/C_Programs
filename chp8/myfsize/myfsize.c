#include "myfsize.h"

long tot_fsize = 0L;

/* print file sizes */
main(int argc, char* argv[])
{
	void myfsize(char* name);
	/* ... */
	int i;

	i = 0;
	if (argc == 1)
		myfsize(".");
	else
		while (--argc > 0)
			myfsize(*(argv + i + 1));

	printf("Total: %8ld bytes\n", tot_fsize);
	return(0);
}

/* fsize: print size of file */
void myfsize(char* name)
{
	struct stat stbuf;

	if (stat(name, &stbuf) != -1)
	{
		if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
			mydirwalk(name, myfsize);
		else
		{
			tot_fsize += stbuf.st_size;
			printf("%s: %8ld bytes\n", name, stbuf.st_size);
		}
	}
	else
		fprintf(stderr, "myfsize: can't access %s\n", name);
}
