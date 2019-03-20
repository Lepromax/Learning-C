#include <stdio.h>

void barChart (int len, const int maxLen) {
	if (len > maxLen) {
		len = maxLen;
	}

	for (int i = 0; i < len; ++i) {
		putchar ('|');
	}

	putchar ('\n');
}

int main () {
	const int IN_WORD = 1, OUT_WORD = 0;
	const int MAXLEN = 10;
	int currChar;
	int state = OUT_WORD;
	int wordLeng = 0;
	int lens[MAXLEN];

	for (int i = 0; i < MAXLEN; ++i) {
		lens[i] = 0;
	}


	do {
		currChar = getchar();

		if (currChar == ' ' || currChar == '\t' || currChar == '\n' || currChar == '.') {
			state = OUT_WORD;

			if (wordLeng < MAXLEN - 1) {
				++lens[wordLeng - 1];
			} else {
				++lens[MAXLEN - 1];
			}
			wordLeng = 0;

		} else if (state == OUT_WORD) {
			state = IN_WORD;
		}

		if (state == IN_WORD) {
			++wordLeng;
		}
	} while (currChar != '.');

	printf ("Word length frequency:\n");
	for (int i = 0; i < MAXLEN; ++i) {
		if (i < MAXLEN - 1) {
			printf ("%d characters:\t", i + 1);
		} else {
			printf ("Bigger %d:\t", MAXLEN - 1);
		}

		barChart (lens[i], 100);
	}

	return 0;
}