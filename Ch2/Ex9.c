/* K&R Ex. 2-9: The expression x - 1 is the one's complement of x from 
	bit position 0 to the bit position of the rightmost 1 bit in x. 
	Using this observation, a faster version of bitcount is below. */

#include <stdio.h>

int bitcount(unsigned x)
{
	int b = 0;

	while (x > 0) {
		x &= (x - 1);
		b++;
	}

	return b;
}

main()
{
	unsigned i = 0;

	while (i < 64)
		printf("The number of 1-bits in %d: %d\n", i++, bitcount(i));

	return 0;
}