/* K&R Ex. 3-5: The function itob(n, s, b) that converts the integer 
	n into a base b character representation in the string s. */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>

#define MAXSIZE 100

void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
	int n = INT_MIN + 1;
	char s[MAXSIZE];

	itob(n, s, 16);

	printf("The largest negative integer in this architecture in hex. is %s\n", s);

	return 0;
}

void itob(int n, char s[], int b)
{
	int i, digit, sign;

	sign = (n < 0) ? 1 : 0;

	i = 0;
	do {
		digit = (sign) ? -(n % b) + '0' : n % b + '0';
		if (b > 10 && digit > '9') digit = digit - '9' + 'A' - 1;
		s[i++] = digit;
		n /= b;
	} while (fabs(n) > 0);
	if (sign)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}