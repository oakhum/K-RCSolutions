/* K&R Ex. 4-2: An extension of the function atof to handle scientific
	notation of the form 123.45e-6, where a floating-point number may
	be followed by e or E and an optionally signed exponent. */

#include <stdio.h>
#include <ctype.h>

#define MAXSIZE 50

double atof(char s[]);

int main()
{
	char s[MAXSIZE] = "1e-10";

	printf("Does the function work as intended? %.2f\n", atof(s));

	return 0;
}

/* atof: convert string s to double */
double atof(char s[])
{
	double val, power;
	int i, sign, exp, expneg;

	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	if (tolower(s[i]) == 'e')
		i++;
	expneg = (s[i] == '-') ? 1 : 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (exp = 0; isdigit(s[i]); i++)
		exp = 10 * exp + (s[i] - '0');
	while (exp-- > 0)
		power = (expneg) ? (power * 10) : (power * 0.1);
	return sign * val / power;
}