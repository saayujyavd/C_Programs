#include <stdio.h>

int binsearch(int, int[], int);

/* binary search */

main()
{
	int a[7] = { 1, 2, 3, 4, 5, 6, 7 };
	int f;

	f = 5;
	printf("%d\n", binsearch(f, a, 7));

	return(0);

}

int binsearch(int x, int v[], int n)
{
	int low, high, mid, omid;

	low = 0;
	high = n - 1;
	omid = (low + high) / 2;

	while (low < high)
	{
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;

	}
	if (x == v[mid])
		return(mid);
	else if (x == v[omid])
		return(omid);
	else if (x == v[low])
		return(low);
	else
		return(-1);

}
