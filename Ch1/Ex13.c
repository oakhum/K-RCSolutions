/* K&R Ex. 1-13: A program which prints a 
	histogram of the lengths of words in its input. */

#include <stdio.h>
#define MAXSIZE 20
#define IN 1
#define OUT 0

main()
{
	int wl[MAXSIZE];
	int chcount, c, i, j, state, max;

	chcount = max = 0;
	state = OUT;
	for (i = 0; i < MAXSIZE; i++)
		wl[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c != ' ' && c != '\t' && c != '\n' && chcount <= MAXSIZE) {
			chcount++; 
			state = IN;
		}
		else if (state == IN) {
			wl[chcount - 1]++;
			state = OUT;
			chcount = 0;
		}
	}

	for (i = 1; i < MAXSIZE; i++)
		if (wl[i] > wl[max])
			max = i;

	for (j = wl[max]; j > 0; j--) {
		for (i = 0; i < MAXSIZE; i++)
			if (j == wl[i]) {
				printf("  *");
				wl[i]--;
			}
		putchar('\n');
	}

	for (i = 0; i < MAXSIZE; i++)
		printf("%3d", i + 1);

	return 0;
}