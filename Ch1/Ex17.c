/* K&R Ex. 1-17: A program that prints all 
	input lines longer than 80 characters. */

#include <stdio.h>

#define MAXSIZE 1000
#define MINLEN 80

int getline(char line[], int maxline);
void copy(char to[], char from[]);

main()
{
	int len, c;
	char line[MAXSIZE];

	while ((len = getline(line, MAXSIZE)) > 0)
		if (len > MINLEN)
			printf("%s", line);

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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}