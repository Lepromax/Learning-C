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
	// maximum length of any line
	const int MAXLINE = 256;

	// length of current and maximum lines
	int curr, max, tmp;

	// current and maximum lines
	char currentLine[MAXLINE], longestLine[MAXLINE];

	max = 0;

	// define a maximum line
	while ((tmp = getLine(currentLine, MAXLINE)) > 0) {
		curr += tmp;
		if (tmp != MAXLINE - 1) {
			if (curr > max) {
			max = curr;
			copy(longestLine, currentLine);
			}
			curr = 0;
		}
	}

	//print a maximum line
	if (max > 0) {
		printf("\nLongest: %d\t%s\n", max, longestLine);
	}

	return 0;
}