#include <stdio.h>

struct Person{
	char name[20];
	float salary;
};

float avarage(struct Person[], int);
struct Person findMin(struct Person[], int n);
float minSalary(struct Person[]);

int main(){
	struct Person employees[3];
	int i;
	for (i=0; i<3; ++i){
		printf("Enter the %d. person's informations: ", i+1);
		scanf("%s %f", employees[i].name, &employees[i].salary);
	}
	
	printf("Avarage of salaries is %f", avarage(employees, 3));
	
	struct Person min=findMin(employees, 3);
	printf("\nlowest salary person is %s. his salary is: %f", min.name, min.salary);
	printf("\nlow salary: %f", minSalary(employees) );
	
	
	return 0;
}

float avarage(struct Person K[], int n){
	int i; 
	float total=0;
	for (i=0; i<n; i++){
		total+=K[i].salary;
	}
	return total/n;
}

struct Person findMin(struct Person K[], int n){
	int i;
	float min=K[0].salary;
	int index=0;
	for (i=1; i<n; ++i){
		if (K[i].salary < min){
			min=K[i].salary;
			index=i;
		}
	}
	return K[index];
}

float minSalary(struct Person K[]){
	int i;
	float min=K[0].salary;
	for (i=1; i<3;i++){
		if (K[i].salary<min){
			min=K[i].salary;
		}
	}
	return min;
	
}
