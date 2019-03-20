#include <stdio.h>

int input(int *n, char ch) {

	printf("Enter the %c number: ", ch);
	scanf("%d", n);

	return *n;
}

int power(int base, int n) {

	int p;

	for(p = 1; n > 0; --n)
		p = p * base;

	return p;
}

int main() {
	
	int m, n;

	m = input(&m, 'M');
	n = input(&n, 'N');

	printf("M ^ N = %d\n", power(m, n));

	return 0;
}