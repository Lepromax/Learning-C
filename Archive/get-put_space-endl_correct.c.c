#include <stdio.h>

int main() {
	
	for(int c; (c = getchar()) != '.';) {

		if(c == ' ')
			putchar('\n');

		else putchar(c);
	}

	return 0;
}