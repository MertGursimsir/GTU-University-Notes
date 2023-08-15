#include <stdio.h>

void triangle(int height){
	int row, column;
	
	for (row=1; row<=height; row++){
		for (column=1; column<=row; column++){
			printf("*");
		}
		printf("\n");
	}
}

int main()
{
	int n;
	while (1){
		printf("Enter the height of the triangle: ");
		scanf("%d", &n);
		if (n==-1){
			printf("Good-bye!");
			break;
		}
		else if (n<0){
			printf("You have entered the negative number.\n");
			continue;
		}
			
		triangle(n);
	}
	return 0;
}
