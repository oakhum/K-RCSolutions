/* K&R Ex. 3-6: A version of itoa that also accepts a third argument
	for minimum field width; the converted number is padded with 
	blanks on the left if necessary to meet the required field width. */

#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAXSIZE 100

void itoa(int n, char s[], int min);
void reverse(char s[]);

int main()
{
	int n = -64;
	char s[MAXSIZE];

	itoa(n, s, 5);

	printf("Derp%s\n", s);

	return 0;
}

void itoa(int n, char s[], int min)
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
	while (i < min)
		s[i++] = ' ';
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