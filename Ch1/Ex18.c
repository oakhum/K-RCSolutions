/* K&R Ex. 1-18: A program that removes trailing blanks and
	tabs from each line of input and deletes entirely blank lines. */

#include <stdio.h>

#define MAXSIZE 1000

main()
{
	int len, c, i;
	char line[MAXSIZE];

	while ((len = getline(line, MAXSIZE)) > 0) {
		for (i = 0; line[i] == ' ' || line[i] == '\t' || line[i] == '\n'; i++)
			;
		while (line[i] != '\0')
			putchar(line[i++]);
	}
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