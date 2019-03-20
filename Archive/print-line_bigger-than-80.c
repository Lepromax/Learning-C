#include <stdio.h>

// get a line
int getLine (char line[], int limit) {
	int currChar, i;

	for (i = 0; i < limit - 1 && (currChar = getchar()) != '.' && currChar != '\n'; ++i) {
		line[i] = currChar;
	}

	if (currChar == '\n') {
		line[i] = currChar;
		++i;
	}

	line[i] = '\0';

	return i;
}

// copy current line to maxinum line
void copy (char to[], char from[]) {
	int i = 0;

	while ((to[i] = from[i]) != '\0') {
		++i;
	}
}

int main () {
	const int MAXLINE = 1000, BORDER = 10;
    char currLine[MAXLINE];
    int len;
    
    len = 0;
    while ((len = getLine(currLine, MAXLINE)) > 0) {
        if (len > BORDER + 1) {
			printf ("\n%s\n", currLine);
		}
    }

	return 0;
}