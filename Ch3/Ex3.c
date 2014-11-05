/* K&R Ex. 3-3: A function expand(s1, s2) that expands shorthand 
	notations such as a-z in s1 to the complete list abc...xyz in s2. */

#include <stdio.h>

#define MAXLINE 300

void expand(char s1[], char s2[]);

int main()
{
	char a[MAXLINE] = "-a-z0-9a-b-c";
	char b[MAXLINE];

	expand(a, b);

	printf("%s\n", b);

	return 0;
}

void expand(char s1[], char s2[])
{
	int i, j;
	char a, b;

	i = j = 0;
	while (s1[i] != '\0')
		if (s1[i + 1] == '-' && ((isupper(s1[i]) && isupper(s1[i + 2]))
		|| (islower(s1[i]) && islower(s1[i + 2])) || (isdigit(s1[i]) && isdigit(s1[i + 2])))) {
			for (a = s1[i], b = s1[i + 2]; a < b; a++, j++) s2[j] = a;
			i += 2;
		}
		else
			s2[j++] = s1[i++];
}