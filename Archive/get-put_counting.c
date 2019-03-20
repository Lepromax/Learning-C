#include <stdio.h>

int input(int *n) {

	printf("Enter an any number: ");
	scanf("%d", n);

	return *n;
}

int main() {
	
	double nc;
	int	nl = 1,
		tab = 0,
		sp = 0;
	int c;

	for(nc = 0; (c = getchar()) != '.'; ++nc) {

		if(c == '\n') ++nl;
		if(c == '\t') ++tab;
		if(c == ' ') ++sp;
	}

	printf("Symbols: %.0f\n", nc);
	printf("Strings: %d\n", nl);
	printf("Tabulations: %d\n", tab);
	printf("Spaces: %d\n", sp);

	return 0;
}