/* K&R Ex. 2-4: An alternative version of squeeze(s1, s2) that 
	deletes each character in s1 that matches any character in s2. */

#include <stdio.h>

#define MAXSIZE 500

void squeeze(char s1[], char s2[]);

main()
{
	char in[MAXSIZE], del[MAXSIZE];

	printf("Input a string: ");
	getline(in, MAXSIZE);
	printf("Input the characters to delete: ");
	getline(del, MAXSIZE);

	squeeze(in, del);
	printf("Did the function work?\n%s", in);

	return 0;
}	

void squeeze(char s1[], char s2[])
{
	int i, j, k;

	for (k = 0; s2[k] != '\0'; k++) {
		for (i = j = 0; s1[i] != '\0'; i++)
			if (s1[i] != s2[k])
				s1[j++] = s1[i];
		s1[j] = '\0';
	}
}