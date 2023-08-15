#include <stdio.h>

int main(){
	int i, x=1;
	printf("number: ");
	scanf("%d", &i);
	while (i>0){
		x*=i;
		i--;
	}
	printf("%d",x);
	return 0;
}
