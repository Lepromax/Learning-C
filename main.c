#include "mylib.h"

int main () {
	const int SIZE = 100;
	int arr[SIZE];
	int i, x, index;

	for (i = 0; i < SIZE; i++) {
		arr[i] = i * i;

	}
	for (i = 0; i < SIZE; i++) {
		printf ("%3d - %4d %c", i, arr[i], ((i+1)%5) ? '|' : '\n');

	}
	printf ("\n");

	x = 3844;
	index = binSearch (x, arr, SIZE);

	printf ("%3d - %4d\n", index, x);

	return 0;
}