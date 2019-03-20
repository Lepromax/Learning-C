#include <stdio.h>

int input(int *n) {

	printf("Enter an any number: ");
	scanf("%d", n);

	return *n;
}

struct position {
	float x;
	float y;
	float z;
};

int main() {
	
//	int num = input(&num);
//	printf("This number is %d\n", num);

	struct position obj_1 = {10, 22, 0.2};

	printf("Obj_1 position is:\n"
		   "X = %.2f\nY = %.2f\nZ = %.2f\n",
		   obj_1.x, obj_1.y, obj_1.z);

	return 0;
}