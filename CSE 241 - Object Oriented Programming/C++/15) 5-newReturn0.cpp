// Fig. 16.5: Fig16_05.cpp
// Demonstrating pre-standard new returning 0 when memory
// is not allocated.
#include <iostream>
using std::cerr;
using std::cout;

int main()
{
	double *ptr[ 50 ];

	// allocate memory for ptr
	for ( int i = 0; i < 50; i++ )
	{
		ptr[ i ] = new double[ 50000000 ];

		if ( ptr[ i ] == 0 ) // did new fail to allocate memory
		{					 // new will have returned 0 if the memory allocation operation failed
			cerr << "Memory allocation failed for ptr[ " << i << " ]\n";
			break;
		} // end if
		else // successful memory allocation
			cout << "Allocated 50000000 doubles in ptr[ " << i << " ]\n";
	} // end for

	return 0;
} // end main

/*

SAMPLE OUTPUT
-------------
Allocated 50000000 doubles in ptr[ 0 ]
Allocated 50000000 doubles in ptr[ 1 ]
Allocated 50000000 doubles in ptr[ 2 ]
Memory allocation failed for ptr[ 3 ]

*/