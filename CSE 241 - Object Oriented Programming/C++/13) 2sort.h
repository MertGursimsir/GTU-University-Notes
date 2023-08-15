#include <iostream>
using std::cout;
using std::endl;

template<class T>
void sort(T a[], int numberUsed);
//Precondition: numberUsed <= declared size of the array a.
//The array elements a[0] through a[numberUsed - 1] have values.
//The assignment and < operator work for values of type T.
//Postcondition: The values of a[0] through a[numberUsed - 1] have
//been rearranged so that a[0] <= a[1] <=... <= a[numberUsed - 1].

template<class T>
void swapValues(T& variable1, T& variable2);
//Interchanges the values of variable1 and variable2.
//The assignment operator must work correctly for thwe type T.

template<class T>
int indexOfSmallest(const T a[], int startIndex, int numberUsed);
//Precondition: 0 <= startIndex < numberUsed. Array elements have values.
//The assignment and < operator work for values of type T.
//Returns the index i such that a[i] is the smallest of the values
//a[startIndex], a[startIndex + 1],..., a[numberUsed - 1].

#include "sort.cpp"
//I have to send implementation file (sort.cpp) to the customer
//He/she is not suppossed to look at sort.cpp