/* K&R Ex. 3-1: A version of binsearch with only one test inside the loop; the 
	difference in runtime is measured compared to the version in the text. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAYSIZE 30

int binsearch(int x, int v[], int n);
int binsearchmk2(int x, int v[], int n);

int main()
{
	time_t start, end;
	int a[ARRAYSIZE] = {3, 9, 10, 10, 11, 12, 14, 18, 27, 29,
						30, 31, 32, 33, 33, 35, 37, 38, 40, 44,
						48, 51, 52, 64, 69, 71, 73, 82, 85, 92};
	int x;

	start = time(&start);
	x = binsearch(37, a, 30);
	end = time(&end);

	printf("Index of element: %d\n", x);
	printf("Text's binsearch runtime: %.2f ns\n", difftime(end, start) * 1000000000.0);

	start = time(&start);
	x = binsearchmk2(37, a, 30);
	end = time(&end);

	printf("Index of element: %d\n", x);
	printf("binsearchmk2 runtine: %.2f ns\n", difftime(end, start) * 1000000000.0);

	return 0;
}
	
// binsearch from the text
int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid + 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

// binsearch with one test inside loop
int binsearchmk2(int x, int v[], int n)
{
	int low = 0;
	int high = n - 1;
	int mid = (low + high) / 2;

	while (low < high) {
		if (x <= v[mid])
			high = mid;
		else
			low = mid + 1;
		mid = (low + high) / 2;
	}

	return (x == v[low]) ? low : -1;
}