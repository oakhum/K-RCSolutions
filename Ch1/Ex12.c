/* K&R Ex. 1-12: A program that prints 
	its input one word per line. */

#include <stdio.h>

main()
{
	int c;

	while ((c = getchar()) != EOF)
		if (c == ' ' || c == '\t' || c == '\n') {
			putchar('\n');
			while ((c = getchar()) == ' ' || c == '\t' || c == '\n')
				;
			putchar(c);
		}
		else
			putchar(c);
}