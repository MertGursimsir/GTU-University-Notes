// Fig. 8.15: Increment.java
// final instance variable in a class.

public class Increment
{
	private int total = 0; // total of all increments

	private final int INCREMENT; // (uninitialized) constant variable, 
								 //not gonna change when initialized in constructor 

	// constructor initializes final instance variable INCREMENT
	public Increment( int incrementValue )
	{
		INCREMENT = incrementValue; // initialize constant variable (once)
	} // end Increment constructor

	// add INCREMENT to total
	public void addIncrementToTotal()
	{
		total += INCREMENT;
	} // end method addIncrementToTotal

	// return String representation of an Increment object's data
	// toString is inherited from Object class
	// If you don't override it, it will give you a string of classname+memorylocation(in JVM)
	public String toString()
	{
		return String.format( "total = %d", total );
		//String.format is like fprintf in C
	} // end method toIncrementString
} // end class Increment