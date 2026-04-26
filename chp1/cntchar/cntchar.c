#include <stdio.h>

#define RETURN '\n'

main()
{
	double nc;

	for (nc = 0; getchar() != RETURN; ++nc)
		;
	printf("%.0f\n", nc);

}
