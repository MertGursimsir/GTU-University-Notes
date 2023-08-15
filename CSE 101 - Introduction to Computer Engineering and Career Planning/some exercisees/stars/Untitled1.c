#include <stdio.h>

int main()
{
	int h,i,j;
	printf("height: ");
	scanf("%d", &h);
	
	for (i=1; i<=h; i++){
		for (j=1; j<=i; j++){
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
