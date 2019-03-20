#include <stdio.h>

// Assignment value to arguments
int assign(char arg) {
    int input;
    printf("Select the value of the argument %c", arg);
    scanf("%d", &input);
    if (input == 0) return 0;
    else return 1;
}

// Print a value of arguments
void show(int s, int p, int res) {
    printf("S\tP\n");
    printf("%d\t%d\t%d\n", s, p, res);
}

// Logical and
int and(int s, int p) {
    if(s == 1 && p == 1) return 1;
    else return 0;
}

// Logical or
int or(int s, int p) {
    if(s == 1 || p == 1) return 1;
    else return 0;
}

// Logical xor
int xor(int s, int p) {
    if(s == 1 && p == 1) return 0;
    else if (s == 1 || p == 1) return 1;
    else return 0;
}

// Logical not
int not(int a) {
    if(a == 1) return 0;
    else return 1;
}

int main()
{
    int s, p;

    s = assign('S');
    p = assign('P');

    show(s, p, or(s, p));

    return 0;
}