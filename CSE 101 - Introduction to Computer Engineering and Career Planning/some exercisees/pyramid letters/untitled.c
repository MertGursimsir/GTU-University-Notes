#include <stdio.h>

int main(){
	
	int a=65, b, i, j;
	
	printf("number: ");
	scanf("%d", &b);
	
	for (i=1; i<=b; i++){
		for (j=1; j<=i; j++){
			printf("%c ", a+(j-1));
		}
		printf("\n");
	}
	
	return 0;
}
