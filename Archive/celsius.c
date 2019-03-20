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

	float fahr, cels = low;

	printf("Cels\t");
	printf("%7s", "Fahr\n");

	while(cels <= upp) {

		fahr = cels * (9.0 / 5.0) + 32.0;
		printf("%4.0f\t%6.1f\n", cels, fahr);
		cels += step;
	}

	return 0;
}