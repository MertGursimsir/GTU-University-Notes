#include <stdio.h>

int main()
{
	int h,i,j;
	printf("height: ");
	scanf("%d", &h);
	
	for (i=h; i>=1; i--){
		for (j=i; j>0; j--){
			printf(" ");
		}
		for (j=h; j>0; j--){
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}
