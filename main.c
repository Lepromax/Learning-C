#include "mylib.h"

int main () {

	int arr[100];
	int i;

	for (i = 0; i < 100; i++) {
		arr[i] = i * i;
	}

	for (i = 0; i < 100; i++) {
		printf ("%d - %d%c", i, arr[i], (i%5) ? ' ' : '\n');
	}



	return 0;
}