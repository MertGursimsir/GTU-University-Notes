#include <stdio.h>
#include <math.h>

int isMersenne(int num){
	int control=0, e=1, i;
	i=pow(2,e)-1;
	while (num>=i){
		if (num==i)
			control=1;
		else
			control=0;
		e++;
		i=pow(2,e)-1;
	}
	return control;
}

int main(){
	int number, result;
	do{
		printf("Enter a number bigger than 1: ");
		scanf("%d", &number);
	}while(number<2);

	result=isMersenne(number);
	
	if (result==1)
		printf("Your number is mersenne prime.");
	else
		printf("Your number is not mersenne prime.");
	return 0;
}
