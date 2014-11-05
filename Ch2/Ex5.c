/* K&R Ex. 2-5: The function any(s1, s2) which returns the first 
	location in string s1 where any character from the string s2 
	occurs, or -1 if s1 contains no characters from s2. */

#include <stdio.h>

#define MAXSIZE 500

int any(char s1[], char s2[]);

main()
{
	char in[MAXSIZE], find[MAXSIZE];

	printf("Input a string: ");
	getline(in, MAXSIZE);
	printf("Input the characters to search for: ");
	getline(find, MAXSIZE);

	printf("Did the function work?\n%d", any(in, find));

	return 0;
}	

int any(char s1[], char s2[])
{
	int i, j;

	for (i = 0; s1[i] != '\n'; i++)
		for (j = 0; s2[j] != '\n'; j++)
			if (s1[i] == s2[j])
				return i;

	return -1;
}