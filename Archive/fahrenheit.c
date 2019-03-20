#include <stdio.h>

int input(int *n) {

	printf("Enter an any number: ");
	scanf("%d", n);

	return *n;
}

int main() {
	
	int low = 0,
		upp = 300,
		step = 20;

	float fahr = low,
		cels;

	printf("Fahr\t");
	printf("Cels\n");

	while(fahr <= upp) {

		cels = (5.0 / 9.0) * (fahr - 32.0);
		printf("%4.0f\t%4.1f\n", fahr, cels);
		fahr += step;
	}

	return 0;
}