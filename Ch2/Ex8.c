/* K&R Ex.2-8: A function rightrot(x, n) that returns the value 
	of the integer x rotated to the right by n positions. */

#include <stdio.h>

unsigned rightrot(unsigned x, int n)
{
	while (n > 0) {
		if (x & 1 == 1)
			x = (x >> 1) | ~(~0U >> 1);
		else
			x = (x >> 1);
		n--;
	}

	return x;
}

main()
{
	int i = 0;
	const int n = 3;

	while (i < 64)
		printf("Integer %d rotated to the right by %d positions: %d\n",
			i++, n, rightrot(i, n));

	return 0;
}