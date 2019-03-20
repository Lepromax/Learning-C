#include <stdio.h>

int input(int *n) {

	printf("Enter an any number: ");
	scanf("%d", n);

	return *n;
}

int main() {
	
	int c = getchar();

	while (c != EOF) {

		putchar(c);
		c = getchar();
	}

	return 0;
}