#include <stdio.h>

int isInRange(int up, int low, int num){
	if (num<up && num>low)
		return 1;
	else 
		return 0;
}

int main(){
	
	int up, low, num, total=0, value;
	
	printf("Enter the lower limit: ");
	scanf("%d", &low);
	printf("Enter the upper limit: ");
	scanf("%d", &up);
	
	while (1){
		printf("Enter a number: ");
		scanf("%d", &num);
		if (num==-1)
			break;
		value=isInRange(up,low,num);
		if (value==1)
			total++;
		else
			continue;
	}
	
	if (total==0)
		printf("There isn't any number between the upper and lower limits.");
	else if (total==1)
		printf("There is 1 number between the upper and lower limits.");
	else
		printf("There are %d numbers between the upper and lower limits.", total);	
			
	return 0;
}
