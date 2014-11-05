/* K&R Ex. 1-23: A program that removes 
	all comments from a C program. */

#include <stdio.h>

#define MAXLINE 100

int getline(char s[], int lim);
int decom(char from[], char to[], int incom);

main()
{
	char in[MAXLINE], out[MAXLINE];
	int len, incom;

	incom = 0;
	while ((len = getline(in, MAXLINE)) > 0) {
		incom = decom(in, out, incom);
		printf("%s", out);
	}

	return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
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

/* decom: copies from into to while removing comments,
	returns state of in/out of a comment */
int decom(char from[], char to[], int incom)
{
	int i, j, sing, mult;

	sing = mult = 0;
	for (i = j = 0; from[i] != '\0'; i++) {
		if (from[i] == '/')
			switch (from[i + 1]) {
				case '/': sing = incom = 1; break;
				case '*': mult = incom = 1; break;
				default: break;
			}
		if (!incom) {
			to[j] = from[i];
			j++;
		}
		if (mult && (from[i] == '*' && from[i + 1] == '/')) {
			i++; mult = incom = 0; continue;
		}
	}

	to[j] = '\n'; to[j + 1] = '\0';
	if (mult)
		return 1;
	else
		return 0;
}
