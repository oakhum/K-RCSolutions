/* K&R Ex. 1-14: A program that prints a histogram of
	the frequencies of different characters in its input. */

#include <stdio.h>

main()
{
	int letct, numct, symct, whtct;
	int c, i, j, max;

	letct = numct = symct = whtct = 0;
	while ((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9')
			numct++;
		else if ((c >= 'a' && c <= 'z')
				|| (c >= 'A' && c <= 'Z'))
			letct++;
		else if (c == ' ' || c == '\t' || c == '\n')
			whtct++;
		else
			symct++;
	}

	max = letct;
	if (numct > max)
		max = numct;
	if (symct > max)
		max = symct;
	if (whtct > max)
		max = whtct;

	for (j = max; j > 0; j--) {
		for (i = 0; i < 4; i++) {
			if (j == letct) {
				printf("%6c ", '*');
				letct--;
			}
			else
				printf("%6c ", ' ');
			if (j == numct) {
				printf("%6c ", '*');
				numct--;
			}
			else
				printf("%6c ", ' ');
			if (j == symct) {
				printf("%6c ", '*');
				symct--;
			}
			else
				printf("%6c ", ' ');
			if (j == whtct) {
				printf("%6c ", '*');
				whtct--;
			}
			else
				printf("%6c ", ' ');
		}
		putchar('\n');
	}
	printf("Letter Number Symbol Whites\n");

	return 0;
}