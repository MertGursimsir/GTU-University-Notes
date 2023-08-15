#include <stdio.h>

main(){
int x;
FILE *A, *B;
A = fopen("person.txt","r");
B = fopen("taxes.txt","a"); // Appened to the existing file

char name[10];
int income;
float tax;
float taxRate;

if (A==NULL){
	printf("The file is not exist\n");
}
else
{
	while(fscanf(A,"%s %d",&name,&income)!=EOF){
		if (income>100)
			taxRate =0.60;
		else
			taxRate = 0.20;
			
		tax = taxRate*income;
		
		fprintf(B,"%-10s %-5d %-9.2f %5f \n",name, income, tax, taxRate);
	}
	fclose (A);
	fclose (B);
}
}
