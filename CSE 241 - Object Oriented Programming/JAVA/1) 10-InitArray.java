// Fig. 7.21: InitArray.java
// Using command-line arguments to initialize an array.

public class InitArray
{
	public static void main( String args[] )
	{
		// check number of command-line arguments
		if ( args.length != 3 )
			System.out.println(
				"Error: Please re-enter the entire command, including\n" +
				"an array size, initial value and increment." );
		else
		{
			// get array size from first command-line argument
			int arrayLength = Integer.parseInt( args[ 0 ] );
			int array[] = new int[ arrayLength ]; // create array

			// get initial value and increment from command-line argument
			int initialValue = Integer.parseInt( args[ 1 ] );
			int increment = Integer.parseInt( args[ 2 ] );

			// calculate value for each array element
			for ( int counter = 0; counter < array.length; counter++ )
				array[ counter ] = initialValue + increment * counter;

			System.out.printf( "%s%8s\n", "Index", "Value" );
			// display array index and value
			for ( int counter = 0; counter < array.length; counter++ )
				System.out.printf( "%5d%8d\n", counter, array[ counter ] );
		} // end else
	} // end main
} // end class InitArray


/*

SAMPLE DIALOGUE
---------------
java InitArray
Error: Please re-enter the entire command, including
an array size, initial value and increment.

java InitArray 5 0 4
Index Value
    0     0
    1     4
    2     8
    3    12
    4    16

java InitArray 10 1 2
Index Value
    0     1
    1     3
    2     5
    3     7
    4     9
    5    11
    6    13
    7    15
    8    17
    9    19

*/