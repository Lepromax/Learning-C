#include "mylib.h"

int main () {

	// Declaration and define array for a string
	const int MAXLINE = 1000;
	int line[MAXLINE];
	int len; // Length of the current string
	for (int i = 0; i < MAXLINE; line[i++] = '\0');

	len = getLine (line, MAXLINE); // Enter the string

	return 0;
}