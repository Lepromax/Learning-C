#include <stdio.h>

int input(int *n) {

	printf("Enter an any number: ");
	scanf("%d", n);

	return *n;
}

int main() {
	
//	int num = input(&num);
//	printf("This number is %d\n", num);

	printf("Здравствуй, мир!\n");

	return 0;
}

