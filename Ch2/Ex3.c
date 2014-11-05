/* K&R Ex. 2-3: A function htoi(s), which converts a string of
	hexadecimal digits into its equivalent integer value. */

#include <stdio.h>
#include <ctype.h>

#define MAXSIZE 20

int getline(char s[], int lim);
int htoi(char s[]);

main() 
{
	char s[MAXSIZE];

	printf("Enter a hexadecimal number: ");
	getline(s, MAXSIZE);
	
	printf("Does the parser work? %d\n", htoi(s));

	return 0;
}

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

int htoi(char s[])
{
	int i = 0;
	int n;

	if (s[i] == '0' && tolower(s[i + 1]) == 'x')
		i += 2;

	for (n = 0; isxdigit(s[i]); i++) {
		if (isalpha(s[i]))
			n = (n * 16) + (tolower(s[i]) - 'a' + 10);
		else
			n = (n * 16) + (s[i] - '0');
	}

	return n;
}