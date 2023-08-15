#include <stdio.h>

int main(){
	
	int i, sum=0, a=0;
	
	while (1){
		printf("number: ");
		scanf("%d", &i);
		if (i==-1)
			break;
		a++;
		sum+=i;
	} 
	
	float average=sum/a;
	printf("%f", average);
	
	
	
	return 0;
}
