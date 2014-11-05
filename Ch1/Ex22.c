/* K&R Ex. 1-22: A program that folds long input lines into
	two shorter lines after the last non-blank character that
	occurs before the n-th column of input. */

#include <stdio.h>

#define MAXSIZE 101
#define FOLDCOLUMN 50

int getline(char s[], int lim);
int searchchar(char s[], int i, int j);
void truncate(char s[], int n);

main()
{
	int len, blank;
	char in[MAXSIZE];

	while ((len = getline(in, MAXSIZE)) > 0) {
		if (len > FOLDCOLUMN) {
			blank = searchchar(in, ' ', FOLDCOLUMN);
			if (blank >= 0) {
				in[blank] = '\n';
				printf("%s\n", in);
			}
			else
				truncate(in, FOLDCOLUMN);
		}
		else
			printf("%s\n", in);
	}

	return 0;
}

/* getline: read a line into s, return length */
int getline(char s[],int lim)
{
	int c, i;

	for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* searchchar: given line s, returns index of char 
	i, starting at int j and counting backward */
int searchchar(char s[], int i, int j)
{
	while (j >= 0) {
		if (s[j] == i)
			return j;
		j--;
	}
	
	return j; // return -1 if no match
}

/* truncate: truncates long line s at column n */
void truncate(char s[], int n)
{
	int i = 0;

	while (i < n) {
		putchar(s[i]);
		i++;
	}
	putchar('\n');
	while (s[i] != '\n' && i < MAXSIZE - 1) {
		putchar(s[i]);
		i++;
	}
	putchar('\n');
}