// Fig. 18.3: GenericMethodTest.java
// Using generic methods to print array of different types.

public class GenericMethodTest
//public class <E> GenericMethodTest  --> makes class generic
{
	// generic method printArray
	public static < E > void printArray( E[] inputArray )
	{
		// display array elements
		for ( E element : inputArray )
			System.out.printf( "%s ", element );
			//all objects have toString method so this is fine with any type

		System.out.println();
	} // end method printArray

	public static void main( String args[] )
	{
		// create arrays of Integer, Double and Character
		Integer[] intArray = { 1, 2, 3, 4, 5 };
		Double[] doubleArray = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
		Character[] charArray = { 'H', 'E', 'L', 'L', 'O' };
		//Integer is class type which derives from Object class like any other classes
		//	 of fundamental type int
		//You have to do this --> Integer i = new Integer(5); 
		//You can also do this--> Integer i2 = 7; 
		//  --> i is reference points to an object in memory which contains an integer.
		//This is called Boxing
		//They are boxed integer (Integer), boxed double (Character), boxed character (Double)
		//We have all kinds of corresponding object types of the fundamental types
		//Those classes are INMUTABLE like string
		//Those are little bit slower than fundamental types

		//We need them because generics won't work with fundamental types
		//For example you cannot have list of ints. You should have:
		//	List<Integer> li = new ArrayList<>();
		//You can add fundamental int after that:
		// for(int i = 1; i < 50; i+=2) li.add(i);
		// COMPILER CONVERTS THIS CODE TO FOLLOWING
		// for(int i = 1; i < 50; i+=2) li.add(Integer.valueOf(i));

		//You can have this:
		//	public static int sumEven(List<Integer> li){
		//		int sum = 0;
		//		for (Integer i : li)
		//			if(i%2==0) sum += i;
		//		return sum;
		//	}
		//COMPILER INVOKES intValue METHOD TO CONVERT AN Integer TO AN int AT RUNTIME
		//	public static int sumEven(List<Integer> li){
		//		int sum = 0;
		//		for (Integer i : li)
		//			if(i.intValue()%2==0) sum += i.intValue();
		//		return sum;
		//	}

		System.out.println( "Array integerArray contains:" );
		printArray( integerArray ); // pass an Integer array
		System.out.println( "\nArray doubleArray contains:" );
		printArray( doubleArray ); // pass a Double array
		System.out.println( "\nArray characterArray contains:" );
		printArray( characterArray ); // pass a Character array
	} // end main
} // end class GenericMethodTest

/*

SAMPLE DIALOGUE
---------------
Array integerArray contains:
1 2 3 4 5 6

Array doubleArray contains:
1.1 2.2 3.3 4.4 5.5 6.6 7.7

Array characterArray contains:
H E L L O

*/