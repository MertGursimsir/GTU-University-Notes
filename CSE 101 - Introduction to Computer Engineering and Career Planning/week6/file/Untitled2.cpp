#include <stdio.h>

main(){
   int A[]={3,4,8,9,6,10,23,41,20,12};
   int B[10];
   for (int i=0; i<10; i++)
   {
      if (A[i]%2!=0)
      {
         B[i]=A[i]*A[i];
      }
      else
      {
         B[i] = A[i]/2;
      }      
   }
   printf("Hello \n");

   for (int i=0; i<10; i++)
   {
      B[i] = B[i]*B[i];
   }
}
