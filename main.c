#include "mylib.h"

int main () {

	int n = 25;

	for (int i = 0; i < n; i++) {
		printf ("%d %% 10 = %d\n", i, i%10);
	}

	return 0;
}