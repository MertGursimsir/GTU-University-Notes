#include <stdio.h>

int isMersenne(int);

int main(){
	int number, a;
	do{
		printf("Enter a number bigger than 1: ");
		scanf("%d", &number);
	}while (number<2);
	
	a = isMersenne(number);
	if (a==1)
		printf("Your number is mersenne prime.");
	else 
		printf("Your number is not mersenne prime.");
	
	return 0;
}

int isMersenne(int num){
	int formula=2;
	while (formula-1<=num){
		if (formula-1==num)
			return 1;
		formula *= 2; 
	}
	return 0;
}
