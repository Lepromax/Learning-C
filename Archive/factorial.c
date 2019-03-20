#include <stdio.h>

int factorial(int n) {
	if(n>1)
		return factorial(n - 1) * n;
	else 
		return 1;
}

int main() {
	
	int num;

	printf("Enter an any number for caclulate its factorial: ");
	scanf("%d", &num);

	printf("Factorial for number %d is %d\n", num, factorial(num));

	return 0;
}