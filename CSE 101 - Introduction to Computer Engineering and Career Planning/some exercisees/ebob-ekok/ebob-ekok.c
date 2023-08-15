#include <stdio.h>

int ekok(int, int);
int ebob(int, int);

int main(){
	int num1, num2, e, k;
	printf("Enter the first number: ");
	scanf("%d", &num1);
	printf("Enter the second number: ");
	scanf("%d", &num2);	
	
	if (num1==num2)
		printf("EBOB(%d, %d) = %d \nEKOK(%d, %d) = %d", num1, num1, num1, num1, num1, num1);
		
	else{
		e = ekok(num1, num2);
		k = ebob(num1, num2);
		printf("EBOB(%d, %d) = %d \nEKOK(%d, %d) = %d", num1, num2, k, num1, num2, e);
	}

	return 0;
}

int ekok(int a, int b){
	int big, small;
	
	if (a<b){
		small = a;
		big = b;
	}
	else{
		small = b;
		big = a;
	}
	
	int ekok;
	ekok = big;
	
	while (ekok%a!=0 || ekok%b!=0)
		ekok++;
		
	return ekok;
	
}

int ebob(int x, int y){
	int big, small;
	
	if (x<y){
		small = x;
		big = y;
	}
	else{
		small = y;
		big = x;
	}
	
	int ebob;
	ebob = small;
	
	while (x%ebob!=0 || y%ebob!=0)
		ebob--;
	
	return ebob;
}
