// Fig. 13.5: UsingExceptions.java
// Demonstration of the try...catch...finally exception handling
// mechanism.

public class UsingExceptions
{
	public static void main( String args[] )
	{
		try
		{
			throwException(); // call method throwException
		} // end try
		catch ( Exception exception ) // exception thrown by throwException
		//catch all kinds of exceptions
		{
			System.err.println( "Exception handled in main" );
		} // end catch

		doesNotThrowException();
	} // end main

	// demonstrate try...catch...finally
	public static void throwException() throws Exception
	{
		try // throw an exception and immediately catch it
		{
			System.out.println( "Method throwException" );
			throw new Exception(); // generate exception
		} // end try
		catch ( Exception exception ) // catch exception thrown in try
		{
			System.err.println("Exception handled in method throwException" );
			throw exception; // rethrow for further processing

			// any code here would not be reached
		} // end catch
		finally // executes regardless of what occurs in try...catch, executes always
		{
			System.err.println( "Finally executed in throwException" );
		} // end finally

		// any code here would not be reached, exception rethrown in catch

	} // end method throwException

	// demonstrate finally when no exception occurs
	public static void doesNotThrowException()
	{
		try // try block does not throw an exception
		{
			System.out.println( "Method doesNotThrowException" );
		} // end try
		catch ( Exception exception ) // does not execute
		{
			System.err.println( exception );
		} // end catch
		finally // executes regardless of what occurs in try...catch
		{
			System.err.println("Finally executed in doesNotThrowException" );
		} // end finally

		System.out.println( "End of method doesNotThrowException" );
	} // end method doesNotThrowException
} // end class UsingExceptions

/*

SAMPLE DIALOGUE
---------------
Method throwException
Exception handled in method throwException
Finally executed in throwException
Exception handled in main
Method doesNotThrowException
Finally executed in doesNotThrowException
End of method doesNotThrowException

*/