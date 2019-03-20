#include <stdio.h>

void swap_elements(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void select_sort(int *c, int l) {

	int smallest;

	for(int i = 0; i < (l-1); i++) {

		smallest = c[i];

		for(int j = i; j < l; j++) {

			if(c[j+1] < smallest)
				smallest = c[j+1];
		}

		swap_elements(c+i, &smallest);
	}
}

int main() {

	int langth = 10;
	int content[langth] = {1, 169, 13, 8, 10, 0, 19, 44, 97, 3}; 

	select_sort(content, langth);

	for(int i = 0; i < langth; i++) {
		printf("%d\n", content[i]);
	}

	return 0;
}