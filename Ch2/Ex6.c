/* K&R Ex. 2-6: A function setbits(x, p, n, y) that returns 
	x with the n bits that begin at position p set to the 
	rightmost n bits of y, leaving the other bits unchanged. */

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	return (x & ((~0 << (p + 1)) | (~(~0 << (p + 1 - n))))) | ((y & ~(~0 << n)) << (p + 1 - n));
}

main()
{
	int x, p, n, y;
	char in[MAXSIZE];

	printf("Enter the integer for x: ");
	getline(in); x = atoi(in);
	printf("Enter the starting position 'p': ");
	getline(in); p = atoi(in);
	printf("Enter the number of bits to change 'b': ");
	getline(in); n = atoi(in);
	printf("Enter the integer for y: ");
	getline(in); y = atoi(in);

	printf("Did the function work? %d\n", setbits(x, p, n, y));

	return 0;
}