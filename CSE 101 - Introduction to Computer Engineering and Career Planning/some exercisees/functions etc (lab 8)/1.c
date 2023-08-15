#include <stdio.h>

int main(){
	int number, max=0;
	while (1){
		printf("Enter a number: ");
		scanf("%d", &number);
		
		if (number==0){
			printf("Max number that you have entered is: %d", max);
			break;
		}
		
		else if (number<0)
			continue;
		
		else
			if (number>max)
				max=number;
			else 
				continue;			
	}

	return 0;
}
