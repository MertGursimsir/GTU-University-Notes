// Fig. 16.2: Fig16_02.cpp
// A simple exception-handling example that checks for
// divide-by-zero exceptions.
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "DivideByZeroException.h" // DivideByZeroException class

// perform division and throw DivideByZeroException object if
// divide-by-zero exception occurs
double quotient( int numerator, int denominator )
{
	// throw DivideByZeroException if trying to divide by zero
	if ( denominator == 0 )
		throw DivideByZeroException(); // terminate function
		//I make an object of DivideByZeroException class and throw it
		//You can throw int, double, DayOfYear objects, etc.
		//Custom is you throw sth that is derived from runtime_error class 
		//Any catch block that is trying to catch runtime_error will catch DivideByZeroException too
		// bc DivideByZeroException "is a" runtime_error

	// return division result
	return static_cast< double >( numerator ) / denominator;
} // end function quotient

int main()
{
	int number1; // user-specified numerator
	int number2; // user-specified denominator
	double result; // result of division

	cout << "Enter two integers (end-of-file to end): ";

	// enable user to enter two integers to divide
	while ( cin >> number1 >> number2 )
	{
		// try block contains code that might throw exception
		// and code that should not execute if an exception occurs
		// if sth bad happens in try block, try block is immediately terminated
		try
		{
			result = quotient( number1, number2 );
			cout << "The quotient is: " << result << endl;
		} // end try

		// exception handler handles a divide-by-zero exception
		// If sth happens in try part, it has to be a DivideByZeroException, I am gonna catch it
		// DivideByZeroException is type of the exception
		catch ( DivideByZeroException &divideByZeroException )
		{
			cout << "Exception occurred: "
				 << divideByZeroException.what() << endl;
		} // end catch

		cout << "\nEnter two integers (end-of-file to end): ";
	} // end while

	cout << endl;
	return 0; // terminate normally
} // end main

/* 

SAMPLE OUTPUT
-------------
Enter two integers (end-of-file to end): 100 7
The quotient is: 14.2857
Enter two integers (end-of-file to end): 100 0
Exception occurred: attempted to divide by zero
Enter two integers (end-of-file to end): ^Z

*/