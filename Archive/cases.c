#include <stdio.h>

int print() {

	int n = 0;

	printf("Enter an any number: ");
	scanf("%d", &n);

	return n;
}

int main() {
	
	int num = print();

	switch (num) {

		case -1:
			printf("Water froze\n");
			break;
		case 100:
			printf("Water bolied\n");
			break;
		default:
			printf("Water is warm\n");

	}

	return 0;
}