#include <stdio.h>

#define STRT 0
#define END 999
/* Assuming STRT <= END for this program */

#define STEP 1.0f
/* Assuming value of STEP >= 0 & of float-type */

/* convert fahrenheit to celcius using a function */

float celcius(float fahrenheit);

main()
{
	float fahrenheit, celc;

	fahrenheit = STRT;
	while (fahrenheit <= END)
	{
		celc = celcius(fahrenheit);
		printf("%.0f\t%.2f\n", fahrenheit, celc);

		fahrenheit = fahrenheit + STEP;

	}

	return(0);

}

float celcius(float fahr)
{
	return((5.0f / 9.0f) * (fahr - 32.0f));

}
