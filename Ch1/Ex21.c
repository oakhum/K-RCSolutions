/* K&R Ex. 1-21: A program entab that replaces strings of
	blanks by the minimum number of tabs and blanks for
	the same spacing. */

#include <stdio.h>

#define MAXSIZE 1000
#define TABSIZE 6

int getline(char s[], int lim);
void entab(char s[], char t[], int tab);

main()
{
	int len;
	char in[MAXSIZE], out[MAXSIZE];

	while ((len = getline(in, MAXSIZE)) > 0) {
		entab(in, out, TABSIZE);
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

void entab(char s[], char t[], int tab)
{
	int i, j, k;

	for (i = j = 0; s[i] != '\0'; i++) {
		if (s[i] == ' ') {
			for (k = 0; s[i + k] == ' '; k++)
				;
			while ((k - tab) > 0) {
				t[j++] = '\t';
				k -= tab;
			}
			while (k-- > 0)
				t[j++] = ' ';
		}
		else
			t[j++] = s[i];
	}
	t[j] = '\0';
}