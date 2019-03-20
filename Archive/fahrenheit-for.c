#include <stdio.h>

int input(int *n) {

	printf("Enter an any number: ");
	scanf("%d", n);

	return *n;
}

int main() {
	
	const int low = 0, // down temperature border
		up = 300, // up temperature border
		step = 20; // step of loop

	for(int fahr = up; fahr >= low; fahr -= step)
		printf("%3d\t%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));

	return 0;
}