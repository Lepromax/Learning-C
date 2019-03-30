#include "mylib.h"

int main () {
	
	const int MAXLINE = 1000, GAP = 250;
	char s1[MAXLINE],
		 s2[MAXLINE + GAP];
	int i;
	
	for (i = 0; i < MAXLINE + GAP; i++) {
		for (;i < MAXLINE; i++) {
			s1[i] = s2[i] = '\0';
		}
		s2[i] = '\0';
	}

	getLine (s1, MAXLINE);
	
	return 0;
}