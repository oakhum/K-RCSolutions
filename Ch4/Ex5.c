/* K&R Ex. 4-5: The calculator program with access to 
	library functions such as sin, exp, and pow. */
	
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define FUNCTION '1'
#define MAXVAL 100
#define BUFSIZE 100

int getop(char []);
double calcfunctions(char []);
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
			case FUNCTION: push(calcfunctions(s)); break;
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
	if (!isalnum(c) && c != '.' && c != '-') return c;
	i = 0;
	if (c == '-' && !isalnum((next = getch()))) return c;
	else if (c == '-' && isalnum(next)) s[++i] = c = next;
	if (isalpha(c)) while (isalpha(s[++i] = c = getch()));
	if (isdigit(c)) while (isdigit(s[++i] = c = getch()));
	if (c == '.') while (isdigit(s[++i] = c = getch()));
	s[i] = '\0';
	if (c != EOF) ungetch(c);
	return (isalpha(s[0])) ? FUNCTION : NUMBER;
}

double calcfunctions(char s[])
{
	double op2;

	if (!strcmp(s, "sin")) return sin(pop());
	if (!strcmp(s, "cos")) return cos(pop());
	if (!strcmp(s, "tan")) return tan(pop());
	if (!strcmp(s, "exp")) return exp(pop());
	if (!strcmp(s, "log")) return log10(pop());
	if (!strcmp(s, "ln")) return log(pop());
	if (!strcmp(s, "pow")) { op2 = pop(); return pow(pop(), op2); }
	if (!strcmp(s, "sqrt")) return sqrt(pop());

	printf("error: unknown function %s\n", s);
	return 0.0;
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