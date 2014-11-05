/* K&R Ex. 1-9: A program that copies its input
	to its output, replacing each string of one 
	or more blanks by a single blank. */

#include <stdio.h>

main()
{
	int c, blank;

	blank = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			putchar(c);
			while ((c = getchar()) == ' ' || c == '\t' || c == '\n')
				;
		}
		putchar(c);
	}
}