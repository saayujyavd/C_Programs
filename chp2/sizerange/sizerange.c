#include <stdio.h>
#include <limits.h>
#include <float.h>

main()
{
	printf("\nRange of char: %d to %d\nRange of unsigned-char: %d to %d\n", CHAR_MIN, CHAR_MAX, 0, UCHAR_MAX);
	printf("Range of short: %d to %d\nRange of unsigned-short: %d to %d\n", SHRT_MIN, SHRT_MAX, 0, USHRT_MAX);
	printf("Range of int: %d to %d\nRange of unsigned-int: %d to %x\n", INT_MIN, INT_MAX, 0, UINT_MAX);
	printf("Range of long: %d to %d\nRange of unsigned-long: %d to %x\n", LONG_MIN, LONG_MAX, 0, ULONG_MAX);
	printf("Range of float: %f to %f\n", FLT_MIN, FLT_MAX);
	printf("\nRange of double: %lf to %lf\n\n", DBL_MIN, DBL_MAX);
	printf("Range of long-double: %lf to %lf\n", LDBL_MIN, LDBL_MAX);

	return(0);

}
