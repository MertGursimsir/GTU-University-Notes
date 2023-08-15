// Fig. 2.7: Addition.java
// Addition program that displays the sum of two numbers.
import java.util.Scanner; // program uses class Scanner
//We have java.util package and inside that there is A Scanner class
//I am importing that Scanner class (for getting information from standardinput)

public class Addition
{
	// main method begins execution of Java application
	public static void main( String args[] )
	{
		// create Scanner to obtain input from command window
		Scanner input = new Scanner( System.in );
		//On the heap, we make a new Scanner object
		//input is Scanner reference

		//These 3 integers are on the stack
		int number1; // first number to add 
		int number2; // second number to add
		int sum; // sum of number1 and number2

		System.out.print( "Enter first integer: " ); // prompt
		number1 = input.nextInt(); // read first number from user
		//calling nextInt method on input

		System.out.print( "Enter second integer: " ); // prompt
		number2 = input.nextInt(); // read second number from user

		sum = number1 + number2; // add numbers

		System.out.printf( "Sum is %d\n", sum ); // display sum
	} // end method main
} // end class Addition

/* 

SAMPLE DIALOGUE
---------------
Enter first integer: 45
Enter second integer: 72
Sum is 117

*/