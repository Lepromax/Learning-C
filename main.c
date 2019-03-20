#include "mylib.h"

int main () {

	// Declaration and define array for a string
	const int MAXLINE = 1000;
	char line[MAXLINE];
	int len; // Length of the current string
	for (int i = 0; i < MAXLINE; line[i++] = '\0');

	printf ("Enter an any string and use \"~\" to finish\v");
	len = getLine (line, MAXLINE); // Enter the string

	return 0;
}