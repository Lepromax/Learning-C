#include <stdio.h>

int input(int *n) {

	printf("Enter an any number: ");
	scanf("%d", n);

	return *n;
}

int main() {
	
	for(int c = getchar(); c != '.'; c = getchar()) {

		switch(c) {
			
			case '\t':
				putchar('\\');
				putchar('t');
				break;
			case '\b':
				putchar('\\');
				putchar('t');
				break;
			case '\\':
				putchar('\\');
				putchar('\\');
				break;
			default:
				putchar(c);
		}
    }

	printf("\n");

	return 0;
}