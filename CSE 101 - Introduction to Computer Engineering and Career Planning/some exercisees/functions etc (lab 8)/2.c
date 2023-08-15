#include <stdio.h>

void triangle(int);

int main()
{
	int n;
	printf("Enter the height of the triangle: ");
	scanf("%d", &n);
	triangle(n);
	return 0;
}

void triangle(int height){
	int row, column;
	
	for (row=1; row<=height; row++){
		for (column=1; column<=row; column++){
			printf("*");
		}
		printf("\n");
	}
}
