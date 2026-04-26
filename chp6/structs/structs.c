#include <stdio.h>
#include <math.h>

struct point
{
	double x, y;
};

struct rect
{
	struct point pt1, pt2;
};

/* calculate area of a rectangle using the two points of it's diagonal */

main(int argc, char* argv[])
{
	struct rect rect;
	double len;

	if (argc < 2)
	{
		printf("Usage: structs.exe <abscissa of point A> <ordinate of point A> <abscissa of point B> <ordinate of point B>\n");
		return(1);
	}
	else
	{
		rect.pt1.x = *argv[1];
		rect.pt1.y = *argv[2];
		rect.pt2.x = *argv[3];
		rect.pt2.y = *argv[4];
		len = sqrt(pow(rect.pt1.x - rect.pt2.x, 2));
		printf("Area: %lf\n", len * sqrt(pow(sqrt(pow(rect.pt1.x - rect.pt2.x, 2) + pow(rect.pt1.y - rect.pt2.y, 2)), 2) - pow(len, 2)));
	}

	return(0);
}
