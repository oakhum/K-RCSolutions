/* K&R Ex. 2-7: A function invert(x, p, n) that 
	returns x with the n bits that begin at position 
	p inverted, leaving the others unchanged. */

#include <stdio.h>

unsigned invert(unsigned x, int p, int n)
{
	return x ^ ~((~0 << (p + 1)) | (~(~0 << (p + 1 - n))));
}

main()
{
	const int pos = 5;
	const int numofbits = 3;
	int i = 0;
	
	while (i < 64)
		printf("The %d bits starting at position %d of integer %d inverted: %d\n", 
			numofbits, pos, i++, invert(i, pos, numofbits));

	return 0;
}