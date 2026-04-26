#include <stdio.h>

main()
{
	int celcius, fahr;
	int lower, upper, step;

	lower = -54623;
	upper = 457394;
	step = 348;

	for (int fahr = lower; fahr <= upper; fahr = fahr + step)
	{
		celcius = (5 * (fahr - 32) / 9);
		printf("%d\t%d\n", fahr, celcius);

	}

}
