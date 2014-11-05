/* K&R Ex. 1-6: A quick program that verifies that
	the expression getchar() != EOF is 0 or 1. */

#include <stdio.h>

main()
{
	printf("%d\n", getchar() != EOF);
}