#include <stdio.h>
int findmax(int[], int);

main(){
   int nums[]={3,6,9,5,7}, big;
   big = findmax(nums, 5); 
   printf("%d", nums[big]);
}

int findmax(int A[], int n){
   int maxInd=0;
   for (int i=0; i<n; i++){
   if (A[i] > A[maxInd])
      maxInd=i;
   }
   return maxInd;
}
