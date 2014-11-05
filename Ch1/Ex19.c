/* K&R Ex. 1-19: A program that utilizes the function 
	reverse(s), which reverses the character string s. */

#include <stdio.h>

#define MAXSIZE 1000

void reverse(char s[], int i, int j);

main()
{
	int len, c, i;
	char line[MAXSIZE];

	while ((len = getline(line, MAXSIZE)) > 0) {
		reverse(line, 0, len - 2);
		for (i = 0; line[i] != '\0'; i++)
			putchar(line[i]);
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

void reverse(char s[], int i, int j)
{
	int temp;

	if (i < j) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		reverse(s, i + 1, j - 1);
	}
}