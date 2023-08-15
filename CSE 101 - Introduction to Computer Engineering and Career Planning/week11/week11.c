#include <stdio.h>

struct Person{
   char name[10];
   float salary;
};

struct Person findTheLargest(struct Person[], int);

int main(){
   struct Person P[3];



   int i;
   for (i=0; i<3; i++){
      scanf("%s", P[i].name);
      scanf("%f",&P[i].salary);
   }

   struct Person maxElement = findTheLargest(P, 3);
   printf("%s has the largest salary %f.", maxElement.name, maxElement.salary);

   return 0;
}


struct Person findTheLargest(struct Person K[], int n){
   int maxSalary=K[0].salary  , i, ind = 0;
 
   for (i=1; i<n; i++){
      if (K[i].salary>maxSalary){
         maxSalary=K[i].salary;
         ind=i;
      }
   }
   return K[ind];
}
