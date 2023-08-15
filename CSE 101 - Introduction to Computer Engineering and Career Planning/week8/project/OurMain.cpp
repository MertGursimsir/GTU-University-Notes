/* We will create 3 functions and call these 
functions, then we will place these functions 
to a header file.*/

#include <stdio.h>
#include "ourLibrary.h"

main(){
	int A[]={3,5,6,7,0,-2,54,3,12};
	int a, length=9;
	a = findMax(A, length);
	printf("The max element is %d", a);
	a = findMin(A, length);
	printf("\nThe min element is %d", a);
	a = findAverage(A, length);
	printf("\nThe average is %d", a);
}
