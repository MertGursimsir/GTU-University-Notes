// Fig. 16.6: Fig16_06.cpp
// Demonstrating standard new throwing bad_alloc when memory
// cannot be allocated.
#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

#include <new> // standard operator new
using std::bad_alloc;

int main()
{
	double *ptr[ 50 ];

	// allocate memory for ptr
	try
	{
		// allocate memory for ptr[ i ]; new throws bad_alloc on failure
		for ( int i = 0; i < 50; i++ )
		{
			ptr[ i ] = new double[ 50000000 ]; // may throw exception
			//For the modern compilers (C++11), we don't return null for unsuccessful new allocation,
			//  we just throw an exception. 
			cout << "Allocated 50000000 doubles in ptr[ " << i << " ]\n";
		} // end for
	} // end try

	// handle bad_alloc exception
	catch ( bad_alloc &memoryAllocationException )
	{		//new throws bad_alloc exception if the memory allocation operation failed
		cerr << "Exception occurred: "
			 << memoryAllocationException.what() << endl;
	} // end catch

	return 0;
} // end main

/*

SAMPLE OUTPUT
-------------
Allocated 50000000 doubles in ptr[ 0 ]
Allocated 50000000 doubles in ptr[ 1 ]
Allocated 50000000 doubles in ptr[ 2 ]
Exception occurred: bad allocation

*/