/* K&R Ex. 1-3: The temperature conversion program 
	modified to print a heading above the table. */

#include <stdio.h>

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
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%5.0f %7.2f\n", fahr, celsius);
		fahr += step;
	}
}