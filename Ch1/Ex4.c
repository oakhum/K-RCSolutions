/* K&R Ex. 1-4: Prints the corresponding
	Celsius to Fahrenheit table. */

#include <stdio.h>

main()
{
	float fahr, celsius;
	float lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	celsius = lower;
	printf("%s %s\n", "Celsius", "Fahr.");
	while (celsius <= upper) {
		fahr = celsius * (9.0 / 5.0) + 32.0;
		printf("%7.0f %5.2f\n", celsius, fahr);
		celsius += step;
	}
}