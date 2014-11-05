/* K&R Ex. 4-4: The calculator program with functions added to peek
	at the top of the stack, to duplicate the item at the top of the
	stack, to swap the top two elements, and to clear the stack. */
	
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

int getop(char []);
void push(double);
double pop(void);
double peek(void);
void copytop(void);
void swaptoptwo(void);
void clearstack(void);
int getch(void);
void ungetch(int);

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

main()
{
	int type;
	double op2;
	char s[MAXOP];
	
	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER: push(atof(s)); break;
			case '+': push(pop() + pop()); break;
			case '*': push(pop() * pop()); break;
			case '-': op2 = pop(); push(pop() - op2); break;
			case '/': 
				op2 = pop(); 
				if (op2 != 0.0) push(pop() / op2);
				else printf("error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0) push(fmod(pop(), op2));
				else printf("error: zero divisor\n");
				break;
			case '\n': printf("\t%.8g\n", pop()); break;
			default: printf("error: unknown command %s\n", s); break;
		}
	}
	
	return 0;
}

void push(double f)
{
	if (sp < MAXVAL) val[sp++] = f;
	else printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
	if (sp > 0) return val[--sp];
	else {
		printf("error: stack empty\n"); return 0.0;
	}
}

double peek(void)
{
	if (sp > 0) return val[sp - 1];
	else {
		printf("error: stack empty\n"); return 0.0;
	}
}

void copytop(void)
{
	if (sp > 0 && sp < MAXVAL) val[sp++] = peek();
	else printf("error: stack empty or full, can't duplicate top item\n");
}

void swaptoptwo(void)
{
	double x, y;
	if (sp > 1) { x = pop(); y = pop(); push(x); push(y); }
	else printf("error: less than two items in stack");
}

void clearstack(void)
{
	while (sp > 0) pop();
}

int getop(char s[])
{
	int i, c, next;
	
	while ((s[0] = c = getch()) == ' ' || c == '\t') ;
	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '-') return c;
	i = 0;
	if (c == '-' && !isdigit((next = getch()))) return c;
	else if (c == '-' && isdigit(next)) s[++i] = c = next;
	if (isdigit(c)) while (isdigit(s[++i] = c = getch()));
	if (c == '.') while (isdigit(s[++i] = c = getch()));
	s[i] = '\0';
	if (c != EOF) ungetch(c);
	return NUMBER;
}

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE) printf("ungetch: too many characters\n");
	else buf[bufp++] = c;
}