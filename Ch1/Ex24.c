/* K&R Ex. 1-24: A program that checks for mismatched 
	parentheses, curly braces, and brackets within C source code. */

#include <stdio.h>

#define MAXSIZE 500

int stackindex = 0;
char parenstack[MAXSIZE];

int getline(char s[], int lim);
void parencheck(char s[]);
void push(char s);
void pop();
char peek();

main()
{
	int len;
	char in[MAXSIZE];
	extern int stackindex;

	while ((len = getline(in, MAXSIZE)) > 0)
		parencheck(in);

	if (stackindex > 0)
		printf("Mismatched parentheses in code.\n");

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

/* parencheck: checks a single line for parens., braces, and brackets */
void parencheck(char s[])
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		switch (s[i]) {
			case '(': case '[': case '{': push(s[i]); break;
			case ')': case ']': case '}': if (peek() == s[i]) pop(s[i]); break;
			default: break;
		}
}

void push(char s)
{
	extern int stackindex;
	extern char parenstack[MAXSIZE];

	parenstack[stackindex] = s;
	stackindex++;
}

void pop()
{
	extern int stackindex;
	extern char parenstack[MAXSIZE];

	parenstack[stackindex] = '\0';
	stackindex--;
}

char peek()
{
	extern int stackindex;
	extern char parenstack[MAXSIZE];

	return parenstack[stackindex];
}