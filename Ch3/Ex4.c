/* K&R Ex. 3-4: In a two's complement number representation, the text's version of itoa does not 
	handle the largest negative number correctly because the program makes the number positive 
	before processing, and the absolute value of the largest negative number is outside the range 
	covered by a two's complement representation (-(2^(n-1)) to 2^(n-1) - 1). This version prints 
	the value correctly regardless of the machine it runs on. */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>

#define MAXSIZE 100

void itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
	int n = INT_MIN;
	char s[MAXSIZE];

	itoa(n, s);

	printf("The largest negative number in this architecture is %s\n", s);

	return 0;
}

void itoa(int n, char s[])
{
	int i, sign;
	
	sign = (n < 0) ? 1 : 0;

	i = 0;
	do {
		s[i++] = (sign) ? -(n % 10) + '0' : n % 10 + '0';
		n /= 10;
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