#include "mylib.h"

int main () {

	int n = 250;

	for (int i = 0; i < n; i++) {
		printf ("%d %% 100 = %d\n", i, i%10);
	}

	return 0;
}