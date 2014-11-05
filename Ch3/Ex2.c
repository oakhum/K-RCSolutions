/* K&R Ex. 3-2: A function escape(s, t) that converts characters 
	with escape sequences into visible sequences (i.e. newline to 
	'\n') as it copies string t to s. */

#include <stdio.h>

#define MAXLINE 50

void escape(char s[], char t[]);
void revescape(char s[], char t[]);

int main()
{
	char a[MAXLINE] = "\a\b\f\n\r\t\v\\\?\'\"derp";
	char b[MAXLINE], c[MAXLINE];

	escape(b, a);
	revescape(c, b);

	printf("String a: %s\n", a);
	printf("String b: %s\n", b);
	printf("String c: %s\n", c);

	return 0;
}

void escape(char s[], char t[])
{
	int i, j;

	i = j = 0;
	while (t[j] != '\0') {
		s[i++] = '\\';
		switch (t[j]) {
			case '\a': s[i++] = 'a'; break;
			case '\b': s[i++] = 'b'; break;
			case '\f': s[i++] = 'f'; break;
			case '\n': s[i++] = 'n'; break;
			case '\r': s[i++] = 'r'; break;
			case '\t': s[i++] = 't'; break;
			case '\v': s[i++] = 'v'; break;
			case '\\': s[i++] = '\\'; break;
			case '\?': s[i++] = '\?'; break;
			case '\'': s[i++] = '\''; break;
			case '\"': s[i++] = '\"'; break;
			default: s[i - 1] = t[j]; break;
		}
		j++;
	}
}

void revescape(char s[], char t[])
{
	int i, j;

	i = j = 0;
	while (t[j] != '\0') {
		if (t[j] == '\\') switch (t[++j]) {
			case 'a': s[i++] = '\a'; break;
			case 'b': s[i++] = '\b'; break;
			case 'f': s[i++] = '\f'; break;
			case 'n': s[i++] = '\n'; break;
			case 'r': s[i++] = '\r'; break;
			case 't': s[i++] = '\t'; break;
			case 'v': s[i++] = '\v'; break;
			case '\\': s[i++] = '\\'; break;
			case '\?': s[i++] = '\?'; break;
			case '\'': s[i++] = '\''; break;
			case '\"': s[i++] = '\"'; break;
			default: break;
		}
		else
			s[i++] = t[j];
		j++;
	}
}