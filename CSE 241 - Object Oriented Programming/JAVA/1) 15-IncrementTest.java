// Fig. 8.16: IncrementTest.java
// final variable initialized with a constructor argument.

public class IncrementTest
{
	public static void main( String args[] )
	{
		Increment value = new Increment( 5 );

		System.out.printf( "Before incrementing: %s\n\n", value );

		for ( int i = 1; i <= 3; i++ )
		{
			value.addIncrementToTotal();
			System.out.printf( "After increment %d: %s\n", i, value );
		} // end for
	} // end main
} // end class IncrementTest

/*

SAMPLE DIALOGUE
---------------
Before incrementing: total = 0
After increment 1: total = 5
After increment 2: total = 10
After increment 3: total = 15

*/