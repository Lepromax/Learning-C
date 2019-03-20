#include <stdio.h>

int main() {
	
	int age = 23;

	printf("Enter your age: ");
	scanf("%d", &age);

	if (age > 18) {
		printf("Your age is bigger than 18 (%d).\n", age);
	} 
	else if (age < 18) {
		printf("Your age is less than 18 (%d).\n", age);
	}
	else {
		printf("Your age is 18.\n");
	}

	return 0;
}