#include "mylib.h"

int main () {

	int arr[100];
	int i;

	for (i = 1; i < 100; i++) {
		arr[i] = i * i;

	}
	for (i = 1; i < 100; i++) {
		printf ("%4d - %4d%c", i, arr[i], (i%5) ? '|' : '\n');

	}
	printf ("\n");

	return 0;
}