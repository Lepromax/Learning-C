#include <stdio.h>

int input(int *n) {

	printf("Enter an any number: ");
	scanf("%d", n);

	return *n;
}

int main() {
	
	for(int c = getchar(), pre = c; c != '.'; c = getchar()) {

		if(c == ' ') {
			if (pre != ' ') putchar(c);
		}
		else putchar(c);

		pre = c;
    }

	printf("\n");

	return 0;
}