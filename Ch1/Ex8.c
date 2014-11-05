/* K&R Ex. 1-8: A program that counts 
	blanks, tabs, and newlines. */

#include <stdio.h>

main()
{
	int whtsp, c;

	whtsp = 0;
	while ((c = getchar()) != EOF)
		if (c == ' ' || c == '\t' || c == '\n')
			whtsp++;
	printf("%d\n", whtsp);
}