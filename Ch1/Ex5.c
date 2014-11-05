/* K&R Ex. 1-5: The temperature conversion program
	modified to print the table in reverse order. */

main()
{
	float celsius;
	float lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	printf("%s %s\n", "Celsius", "Fahr.");
	for (celsius = upper; celsius >= lower; celsius -= step)
		printf("%7.0f %5.2f\n", celsius, celsius * (9.0 / 5.0) + 32.0);
}