#include <stdio.h>

int input() {

	int n = 0;

	printf("Enter an any number: ");
	scanf("%d", &n);

	return n;
}

int main() {
	
	int len_1 = 9, len_2 = 9;
	char arr[len_1][len_2];

	for(int i = 0; i < len_1; i++){
		for(int j = 0; j < len_2; j++){
			arr[i][j] = (i+1) * (j+1);
		}	
	}

	printf("\n");

	for(int i = 0; i < len_1; i++){
		for(int j = 0; j < len_2; j++){
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}