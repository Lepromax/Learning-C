#include "mylib.h"

int main () {

	int arr[100];
	int i;

	for (i = 0; i < 100; i++) {
		arr[i] = i * i;

	}
	for (i = 0; i < 100; i++) {
		printf ("%3d - %4d %c", i, arr[i], ((i+1)%5) ? '|' : '\n');

	}
	printf ("\n");

	return 0;
}