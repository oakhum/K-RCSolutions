/* K&R Ex. 1-20: A program detab which replaces tabs
	in the input with the proper number of blanks to
	space to the next tab stop. */

#include <stdio.h>

#define MAXSIZE 1000
#define TABSIZE 6

void detab(char s[], char t[], int tab);

main()
{
	int lim;
	char in[MAXSIZE], out[MAXSIZE];

	while ((lim = getline(in, MAXSIZE)) > 0) {
		detab(in, out, TABSIZE);
		printf("%s", out);
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

void detab(char s[], char t[], int tab)
{
	int i, j, k;

	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] == '\t')
			for (k = 0; k < tab; k++)
				t[j++] = ' ';
		else
			t[j++] = s[i];
	t[j] = '\0';
}