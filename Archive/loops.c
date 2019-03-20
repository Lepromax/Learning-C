#include <stdio.h>

int print() {

	int n = 0;

	printf("Enter an any number: ");
	scanf("%d", &n);

	return n;
}

int main() {
	
	int i = 1,
		num = print();

	do {
		printf("%d\n", i++);
	} while (i <= num);

	/*
	while(i <= num) {
		printf("%d\n", i++);
	}

	for(int i = 1; i <= num; i++) {
        printf("%\n", i);
    }
	*/

	return 0;
}