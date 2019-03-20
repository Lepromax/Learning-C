#include <stdio.h>

int main() {
	
	const int IN_WORD = 1, OUT_WORD = 0, // words state
		IN_LINE = 1, OUT_LINE = 0; // lines state

	int lines, words, characters, c,
		wstate = OUT_WORD, lstate = OUT_LINE;

	lines = words = characters = 0;

	do {
		c = getchar();

		// Characters counting
		++characters;

		//	Lines counting
		if(c == '\n') {
			lstate = OUT_LINE;
		}
		else if(lstate == OUT_LINE) {
			lstate = IN_LINE;
			++lines;
		}

		// Words counting
		if(c == ' ' || c == '\t' || c == '\n') {
			wstate = OUT_WORD;
		}
		else if (wstate == OUT_WORD) {
			wstate = IN_WORD;
			++words;
		}

	} while(c != '.');

	printf("Lines: %d\nWords: %d\nCharacters: %d\n", lines, words, characters);

	return 0;
}