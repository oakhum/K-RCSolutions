/* K&R Ex. 2-10: The function lower, which converts upper case letters
	to lower case, with a conditional expression instead of if-else. */

#include <stdio.h>

int lower(int c)
{
	return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}

main()
{
	char c = 'A';

	while (c <= 'Z')
		printf("%c", lower(c++));

	return 0;
}