#include "mylib.h"

int main () {
	
	const int MAXLINE = 1000;
	char original[MAXLINE],
		 changed[(int)1.5 * MAXLINE];
	
	getLine (original, MAXLINE); // Enter a string

	//escape (changed, original); // Copy original to change

	printf ("%s\n", changed);

	return 0;
}