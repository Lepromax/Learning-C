#include <stdio.h>

int input(int *n) {

	printf("Enter an any number: ");
	scanf("%d", n);

	return *n;
}

float fahr_to_cels(int f) {

	return (5.0 / 9.0) * (f - 32);
}

int main() {
	
	const int low = 0, // down temperature border
		up = 300, // up temperature border
		step = 20; // step of loop

	for(int fahr = up; fahr >= low; fahr -= step)
		printf("%3d\t%6.1f\n", fahr, fahr_to_cels(fahr));

	return 0;
}