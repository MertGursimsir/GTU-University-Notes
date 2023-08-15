// Fig. 16.3: Fig16_03.cpp
// Demonstrating exception rethrowing.
#include <iostream>
using std::cout;
using std::endl;

#include <exception>
using std::exception;

// throw, catch and rethrow exception
void throwException()
{
	// throw exception and catch it immediately
	try
	{
		cout << " Function throwException throws an exception\n";
		throw exception(); // generate exception
	} // end try
	catch ( exception & ) // handle exception --> i didnt give parameter name bc i wont use it
	{
		cout << " Exception handled in function throwException"
		<< "\n Function throwException rethrows exception";
		throw; // rethrow exception for further processing
	} // end catch

	cout << "This also should not print\n";
	//Never executed bc nobody catch last throw in line 23 so this function is terminated in line 23
} // end function throwException

int main()
{
	// throw exception
	try
	{
		cout << "\nmain invokes function throwException\n";
		throwException();
		cout << "This should not print\n";
	} // end try
	catch ( exception & ) // handle exception  --> catches rethrown exception
	{
		cout << "\n\nException handled in main\n";
	} // end catch

	cout << "Program control continues after catch in main\n";
	return 0;
} // end main

/*

SAMPLE OUTPUT
-------------
main invokes function throwException
Function throwException throws an exception
Exception handled in function throwException
Function throwException rethrows exception

Exception handled in main
Program control continues after catch in main

*/