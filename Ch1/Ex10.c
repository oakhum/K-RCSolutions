/* K&R Ex. 1-10: A program that copies its input 
	to its output, replacing each tab by \t, each 
	backspace by \b, and each blackslash by \\. */

#include <stdio.h>

main()
{
	int c;
	
	while ((c = getchar()) != EOF)
		switch (c) {
			case '\t': printf("%s", "\\t"); break;
			case '\b': printf("%s", "\\b"); break;
			case '\\': printf("%s", "\\\\"); break;
			default: putchar(c); break;
		}
}