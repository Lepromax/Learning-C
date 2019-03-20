#include <stdio.h>

void progress(int len) {
	
	if(len > 100) len = 100;

	for(int i = 0; i < len; ++i)
		putchar('|');

	putchar('\n');
}

int main() {

	int c, nwhite, nother;
	int ndigit[10];

	for(int i = 0; i < 10; ++i)
		ndigit[i] = 0;

	while((c = getchar()) != '.') {

		if(c >= '0' && c <= '9')
			++ndigit[c - '0'];

		else if(c == ' ' || c == '\t' || c == '\n')
			++nwhite;

		else
			++nother;
	}

	printf("Digits:\n");

	for(int i = 0; i < 10; ++i)
		printf("%d - %d\n", i, ndigit[i]);

	printf("\nSeparators: %d\nOther: %d\n", nwhite, nother);

	return 0;
}