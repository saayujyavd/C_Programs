#include <stdio.h>

main()
{
	float celcius, fahr;
	int lower, upper, step;

	lower = -54623;
	upper = 457394;
	step = 348;

	for (fahr = lower; fahr <= upper; fahr = fahr + step)
	{
		celcius = (5 * (fahr - 32) / 9);
		printf("%f %f\n", fahr, celcius);

	}

}
