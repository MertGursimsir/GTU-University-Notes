#include <stdio.h>

int main(){
	/* (2*satir-1) yildiz
	   (n-satir)  bosluk */
	int row, a, b, c;
	printf("row number:");
	scanf("%d", &row);
	for (a=1; a<=row; a++){
		for (b=1; b<=row-a; b++)
			printf(" ");
		for (c=1; c<=2*a-1; c++)
			printf("*");
		
		printf("\n");
	}
	
	return 0;
}
