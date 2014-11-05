/* K&R Ex. 1-15: A temperature conversion program 
	that uses a function for conversion. */

#include <stdio.h>

float fahrToCel(int fahr);

main()
{
	float fahr, celsius;
	float lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	printf("%s %s\n", "Fahr.", "Celsius");
	while (fahr <= upper) {
		celsius = fahrToCel(fahr);
		printf("%5.0f %7.2f\n", fahr, celsius);
		fahr += step;
	}
}

float fahrToCel(int fahr)
{
	return (5.0 / 9.0) * (fahr - 32.0);
}