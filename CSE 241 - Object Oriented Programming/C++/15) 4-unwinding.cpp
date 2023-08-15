// Fig. 16.4: Fig16_04.cpp
// Demonstrating stack unwinding.
#include <iostream>
using std::cout;
using std::endl;

#include <stdexcept>
using std::runtime_error;

// function3 throws run-time error
void function3() throw ( runtime_error )
{
	cout << "In function 3" << endl;

	// no try block, stack unwinding occur, return control to function2
	throw runtime_error( "runtime_error in function3" );
} // end function3

// function2 invokes function3
void function2() throw ( runtime_error )
{
	cout << "function3 is called inside function2" << endl;
	function3(); // stack unwinding occur, return control to function1
} // end function2

// function1 invokes function2
void function1() throw ( runtime_error )
{
	cout << "function2 is called inside function1" << endl;
	function2(); // stack unwinding occur, return control to main
} // end function1

// demonstrate stack unwinding
int main()
{
	// invoke function1
	try
	{
		cout << "function1 is called inside main" << endl;
		function1(); // call function1 which throws runtime_error
	} // end try
	catch ( runtime_error &error ) // handle run-time error  
	//f3 throwed that error, f2 and f1 didnt catch it, main catched it
	{
		cout << "Exception occurred: " << error.what() << endl;
		cout << "Exception handled in main" << endl;
	} // end catch

	return 0;
} // end main

/*

SAMPLE OUTPUT
-------------
function1 is called inside main
function2 is called inside function1
function3 is called inside function2
In function 3
Exception occurred: runtime_error in function3
Exception handled in main

*/