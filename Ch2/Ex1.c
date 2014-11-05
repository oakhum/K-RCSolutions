/* K&R Ex. 2-1: A program that determines the ranges of signed and 
	unsigned char, short, int, and long variables by direct computation, 
	and the ranges of various floating-point types from standard headers. */

#include <stdio.h>
#include <limits.h>
#include <float.h>

main()
{
	signed char s1 = 0;
	signed short s2 = 0;
	signed int s3 = 0;
	signed long s4 = 0;
	unsigned char u1 = 1;
	unsigned short u2 = 1;
	unsigned int u3 = 1;
	unsigned long u4 = 1;

	while (s1 >= 0) s1++;
	printf("signed char min: %d ", s1); s1--;
	printf("signed char max: %d\n", s1);

	while (s2 >= 0) s2++;
	printf("signed short min: %d ", s2); s2--;
	printf("signed short max: %d\n", s2);

	while (s3 >= 0) s3++;
	printf("signed int min: %d ", s3); s3--;
	printf("signed int max: %d\n", s3);

	while (s4 >= 0) s4++;
	printf("signed long min: %d ", s4); s4--;
	printf("signed long max: %d\n", s4);

	while (u1 > 0) u1++;
	printf("unsigned char min: %d ", u1); u1--;
	printf("unsigned char max: %d\n", u1);

	while (u2 > 0) u2++;
	printf("unsigned short min: %d ", u2); u2--;
	printf("unsigned short max: %d\n", u2);

	/* Compiler-defined maxes for unsigned ints and 
	longs so large the computer goes full retard */
	while (u3 > 0) u3++;
	printf("unsigned int min: %d ", u3); u3 -= 1;
	printf("unsigned int max: %d\n", u3);
	printf("Compiler-defined unsigned int max: %d\n", UINT_MAX); 

	while (u4 > 0) u4++;
	printf("unsigned long min: %d ", u4); u4 -= 1;
	printf("unsigned long max: %d\n", u4);
	printf("Compiled-defined unsigned long max: %d\n", ULONG_MAX);

	printf("float min: %f float max: %f\n", FLT_MIN, FLT_MAX);
	printf("double min: %f double max: %f\n", DBL_MIN, DBL_MAX);

	return 0;
}