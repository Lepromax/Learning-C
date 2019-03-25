#include <stdio.h>
#include <math.h>

int getLine (char line[], int limit) {
    int cChar;
    int i;

    for (i = 0; i < limit-1 && (cChar = getchar ()) != '~'; ++i) {
        line[i] = cChar;
    }

    if (cChar == '~' || cChar == '\n') {
        line[i++] = '\n';
    }
    
    line[i] = '\0';
    
    return i;
}

int getLineSpecial (char line[], int limit) {
    int cChar;
    int i, j;

    for (i = 0, j = 0; i < limit-1; ++i) {
        if ((cChar = getchar ()) != '~') {
            line[j++] = cChar;
        } else {
            line[j++] = '\n';
            line[j] = '\0';
             i = limit-2;
        } 
    }
    
    return j;
}

void copy (char to[], char from[]) {
	int i;

    i = 0;
	while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}

int spaceCorrect (char to[], char from[]) {
	int i, j;
    int sflag;
    int currChar;

    i = 0;
    j = 0;
    sflag = 0;
    while ((currChar = from[i++]) != '\n') {
        if (currChar == ' ' || currChar == '\t') {
            if (sflag == 0) {
                to[j++] = ' ';
                sflag = 1;
            }
        } else {
            to[j++] = currChar;
            sflag = 0;
        }
    }

    if (currChar == '\n') {
       to[j++] = currChar;
    }
    to[j] = '\0';

    return j;
}

int reverseStr (char to[], char from[], int lim) {
    int i;

    for (i = 0; i < lim - 1; ++i) {
        to[lim - 2 - i] = from[i];
    }

    to[i++] = '\n';
    to[i] = '\0';

    return i;
}

int detab (char to[], char from[], int lim) {
    int tflag;
    int currChar;
    int i, j, k;

    tflag = 0;
    i = j = 0;
    while ((currChar = from[i++]) != '\0') {
        if (currChar == '\t') {
            for (k = 0; k < lim; ++k) {
                to[j++] = ' ';
            }
            tflag = 1;
        } else {
            to[j++] = currChar;
        }
    }

    to[j] = '\0';

    return tflag;
}

int entab (char to[], char from[], int lim) {
    int tflag = 0;
    int i, j, k;
    int currChar;

    i = j = 0;
    while ((currChar = from[i++]) != '\0') {
        if (currChar == ' ') {
            if (from[i] == ' ') {
                k = 2;
                while (from[++i] == ' ') {
                    ++k;
                }
                if (k >= lim) {
                    for (; (k / lim) > 0; k -= lim) {
                        to[j++] = '\t';
                    }
                    for (; k > 0; --k) {
                        to[j++] = ' ';
                    }
                    tflag = 1;
                } else {
                    for (;k > 0; --k) {
                        to[j++] = ' ';
                    }
                }
            } else {
                to[j++] = currChar;
            }
        } else {
            to[j++] = currChar;
        }
    }
    
    to[j] = '\0';

    return tflag;
}

void justify (char line[], int lineLen,  int lineLim) {
    const int BORDER = 5;
    int curLineLen, curLineEnd;
    int lastSeparator;
    int curChar;
    int i, j;

    lastSeparator = curLineEnd = i = 0;
    while (lineLen-1 - curLineEnd > lineLim) {
        lastSeparator = curLineEnd;
        curLineEnd += lineLim;

        for (j = curLineEnd - lineLim; j < curLineEnd; ++j) {
            curChar = line[j];
            if (curChar == ' ' || curChar == '\t' || curChar == '\n') {
                lastSeparator = j;
            }
        }

        if (lastSeparator > curLineEnd - BORDER) {
            curLineEnd = lastSeparator;
        }

        while (i < curLineEnd) {
            putchar (line[i++]);
        }
        putchar ('\n');
    }

    while ((curChar = line[i++]) != '\0') {
        putchar(curChar);
    }
}

void commentCorrect (char to[], char from[], int lim) {
    int commentFlag, quoteFlag;
    int currChar;
    int i, j;

    commentFlag = quoteFlag = 0;
    for (i = j = 0; i < lim; ++i) {
        currChar = from[i];

        if (!commentFlag && currChar == '\"' && !quoteFlag) {
            quoteFlag = 1;
        } else if (currChar == '\"' && quoteFlag) {
            quoteFlag = 0;
        }

        if (!quoteFlag && currChar == '/' && !commentFlag) {
            if (from[i+1] == '*') {
                commentFlag = 1;
                i += 1;
                currChar = from[i];
            } else if (from[i+1] == '/') {
                commentFlag = 1;
                i = lim;
            }
        } else if (currChar == '*' && commentFlag) {
            if (from[i+1] == '/') {
                commentFlag = 0;
                i += 1;
                currChar = from[i];
            }
        } else if (!commentFlag) {
            to[j] = currChar;
            ++j;
        }
    }
    to[j] = '\0';
}

void syntaxCheck (char line[], int limit) {
    const int OUT = 0, NO = 0;
    const int IN = 1, YES = 1;
    const int _NULL = '0',
              ROUND = 'r',
              SQUARE = 's',
              TRIANGULAR = 't',
              FIGURE = 'f';

    int i, j;
    int cChar, plusOne;

    // Flags
    int checkF;
    int escapeF;
    int newLineF;
    int siComF, mComF;
    int siQuoteF, dQuoteF;
    int rBracketsF, sqBracketsF, tBracketsF, fBracketsF;

    char bracketsStack[15];

    for (j = 0; j < 15; ++j) {
        bracketsStack[j] = _NULL;

    }

    i = 0;
    j = 0;
    escapeF = NO;
    checkF = YES;
    newLineF = NO;
    siComF = mComF = OUT;
    siQuoteF = dQuoteF = OUT;
    rBracketsF = sqBracketsF = tBracketsF = fBracketsF = OUT;

    while (i < limit) {
        cChar = line[i++];
        plusOne = line[i];

        // New line flag
        if (!newLineF && cChar == '\n') {
            newLineF = YES;

        } else if (newLineF) {
            newLineF = NO;

        }

        // Single line comments
        if (checkF && !siComF && cChar == '/' && plusOne == '/') {
            siComF = IN;
            checkF = NO;

        } else if (!checkF && siComF && newLineF) {
            siComF = OUT;
            checkF = YES;

        }
        
        // Multi line comments
        if (checkF && !mComF && cChar == '/' && plusOne == '*') {
            mComF = IN;
            checkF = NO;

        } else if (!checkF && mComF && cChar == '*' && plusOne == '/') {
            mComF = OUT;
            checkF = YES;

        }

        // Single quotes
        if (checkF && !siQuoteF && cChar == '\'') {
            siQuoteF = IN;
            checkF = NO;

        } else if (!checkF && siQuoteF && cChar == '\'') {
            siQuoteF = OUT;
            checkF = YES;

        }

        // Double quotes
        if (checkF && !dQuoteF && cChar == '\"') {
            dQuoteF = IN;
            checkF = NO;

        } else if (!checkF && dQuoteF && cChar == '\"') {
            dQuoteF = OUT;
            checkF = YES;

        }

        // Round brackets
        if (checkF && cChar == '(') {
            bracketsStack[j++] = ROUND;
            ++rBracketsF;

        } else if (checkF && cChar == ')' &&
            bracketsStack[j-1] == ROUND
            ) {
            bracketsStack[j--] = _NULL;
            --rBracketsF;

        }

        // Square brackets
        if (checkF && cChar == '[') {
            bracketsStack[j++] = SQUARE;
            ++sqBracketsF;

        } else if (checkF && cChar == ']' &&
            bracketsStack[j-1] == SQUARE
            ) {
            bracketsStack[j--] = _NULL;
            --sqBracketsF;

        }

        // Triangular brackets
        if (checkF && cChar == '<') {
            bracketsStack[j++] = TRIANGULAR;
            ++tBracketsF;

        } else if (checkF && cChar == '>' &&
            bracketsStack[j-1] == TRIANGULAR
            ) {
            bracketsStack[j--] = _NULL;
            --tBracketsF;

        }

        // Figure brackets
        if (checkF && cChar == '{') {
            bracketsStack[j++] = FIGURE;
            ++fBracketsF;

        } else if (checkF && cChar == '}' &&
            bracketsStack[j-1] == FIGURE
            ) {
            bracketsStack[j--] = _NULL;
            --fBracketsF;

        }

        if ((siQuoteF || dQuoteF) && cChar == '%' &&
            plusOne != '%' && plusOne != 'i' &&
            plusOne != 'd' && plusOne != 'o' &&
            plusOne != 'x' && plusOne != 'f' &&
            plusOne != 'c' && plusOne != 's'
            ) {
            ++escapeF;

        }
    }

    if (!mComF && !siQuoteF &&
        !fBracketsF && !escapeF &&
        !dQuoteF && !rBracketsF &&
        !sqBracketsF && !tBracketsF
        ) {
        printf ("\nErrors not found\n");

    } else {
        if (mComF != 0) {
            printf ("\nUnclosed comments\n");

        }
        if (siQuoteF != 0) {
            printf ("\nUnclosed single quotes\n");

        }
        if (dQuoteF != 0) {
            printf ("\nUnclosed double quotes\n");

        }
        if (rBracketsF != 0) {
            printf ("\nUnclosed %d round brackets\n", rBracketsF);

        }
        if (sqBracketsF != 0) {
            printf ("\nUnclosed %d square brackets\n", sqBracketsF);

        }
        if (tBracketsF != 0) {
            printf ("\nUnclosed %d triangular brackets\n", tBracketsF);

        }
        if (fBracketsF != 0) {
            printf ("\nUnclosed %d figure brackets\n", fBracketsF);

        }
        if (escapeF != 0) {
            printf ("\n%d unknown escape-sequence\n", escapeF);

        }
    }
}

int typeCheck () {
    long long i, j;
    long long min, max;

    min = max = 0;

    for (i = 1, j = -1; i != 0 && j != 0; ++i, --j) {
        if (i > max) {
            max = i;

        }
        if (j < min) {
            min = j;

        }
    }

    printf ("Min: %lli\nMax: %lli\n", min, max);
}

int htol (char line[], int lim) {
    int current;
    int hex;
    int i, j;

    j = 0;
    while (j < lim && !((line[j++] == '0') && (line[j] == 'x' || line[j] == 'X')));
    
    hex = 0x0;
    if (j != lim) {  
        for (i = ++j; i < lim &&
            (current = line[i]) >= '0' && current <= '9' ||
            current >= 'a' && current <= 'f' ||
            current >= 'A' && current <= 'F';
            ++i) {

            if (current >= '0' && current <= '9') {
                hex = 16 * hex + (current - '0');

            } else if (current >= 'a' && current <= 'f') {
                hex = 16 * hex + (current - 'a' + 10);

            } else if (current >= 'A' && current <= 'F') {
                hex = 16 * hex + (current - 'A' + 10);

            }

        }

    }

    return hex;
}

void squeeze (char s1[], char s2[]) {
    int curChar,
        equalF,
        i, j, k;
    
    i = j = 0;
    while ((curChar = s1[i++]) != '\0') {
        k = 0;
        equalF = 0;
        while (s2[k] != '\0') {
            if (curChar == s2[k++]) {
                equalF = 1;
                break;

            }

        }
        if (!equalF) {
            s1[j++] = curChar;

        }

    }
    s1[j] = '\0';
}

int any (char s1[], char s2[]) {
    int curChar,
        i, j,
        pos;

    pos = -1;
    
    i = 0;
    while ((curChar = s1[i]) != '\0') { 
        j = 0;
        while (s2[j] != '\0') {
            if (s2[j++] == curChar) {
                pos = i;
                break;

            }

        }

        i++;
    }

    return pos;
}

void showBin (unsigned n) {
        for (int i = (sizeof(int)*8-1); i >= 0; i--) {
        printf ("%d", (n >> i) & 1);
        if (i % 8 == 0) {
            putchar (' ');
        }
    }
    printf ("\n");
}

unsigned getBits (unsigned x, int p, int n) {
    return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned setBits (unsigned x, int p, int n, unsigned y) {

    return (x & (~0 << (p+1))) | (x & ~(~0 << (p+1-n))) |
           ((y & ~(~0 << n)) << (p+1-n)); 
}

unsigned invert (unsigned x, int p, int n) {

    return x ^ (~(~0 << n) << (p+1-n));
}

unsigned rightrot (unsigned x, int n) {
    
    for (int i = n; i > 0; i--) {
        x = x >> 1;
        printf ("%d: ", n+1-i);
        showBin (x);
    }

    return x;
}

unsigned bitCount (unsigned x) {
    int i;

    for (i = 0; x != 0; x &= (x-1)) {
        i++;
    }
    
    return i;
}

void lower (char line[]) {
    int cChar;

    for (int i = 0; (cChar = line[i]) != '\0'; i++) {
        line[i] = (cChar >= 'A' && cChar <= 'Z') ? cChar - ('A' - 'a') : cChar;
    }

}

void printChar () {
    
    for (int i = 32; i <= 127; i++) {
        printf ("%c%c", i, (i%10 == 1) ? '\n' : ' ');
    }
    printf ("\n");
}

int binSearch (int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    
    mid = (low + high) / 2;

    while (low <= high && x != v[mid]) {
        if (x < v[mid]) {
            high = mid - 1;

        } else {
            low = mid + 1;

        }
        mid = (low + high) / 2;
    }

    if (x == v[mid]) {
        return mid;

    } else {
        return -1;

    }

}

void escape (char to[], char from[]) {
    int i, j;
    int cChar;

    for (i = 0, j = 0; (cChar = from[i]) != '\0'; i++) {
        
        switch (cChar) {
            case '\n':
                to[j++] = '\\';
                to[j++] = 'n';
                break;
            case '\t':
                to[j++] = '\\';
                to[j++] = 't';
                break;
            default:
                to[j++] = cChar;
        }

    }
}

void reEscape (char to[], char from[]) {
    int i, j;
    int cChar;

    for (i = 0, j = 0; (cChar = from[i]) != '\0'; i++) {
        
        if (cChar == '\\') {
            if (from[i+1] == 'n') {
                to[j++] = '\n';
                i++;

            }
            if (from[i+1] == 't') {
                to[j++] = '\t';
                i++;

            }
        } else {
            to[j++] = cChar;
        }
    }
}