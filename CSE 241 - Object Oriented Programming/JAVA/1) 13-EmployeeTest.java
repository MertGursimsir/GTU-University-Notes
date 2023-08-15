// Fig. 8.13: EmployeeTest.java
// Static member demonstration.

public class EmployeeTest
{
	public static void main( String args[] )
	{
		// show that count is 0 before creating Employees
		System.out.printf( "Employees before instantiation: %d\n",
							Employee.getCount() );

		// create two Employees; count should be 2
		Employee e1 = new Employee( "Susan", "Baker" );
		Employee e2 = new Employee( "Bob", "Blue" );

		// show that count is 2 after creating two Employees
		System.out.println( "\nEmployees after instantiation: " );
		System.out.printf( "via e1.getCount(): %d\n", e1.getCount() );
		System.out.printf( "via e2.getCount(): %d\n", e2.getCount() );
		System.out.printf( "via Employee.getCount(): %d\n",
							Employee.getCount() );

		// get names of Employees
		System.out.printf( "\nEmployee 1: %s %s\nEmployee 2: %s %s\n\n",
							e1.getFirstName(), e1.getLastName(),
							e2.getFirstName(), e2.getLastName() );

		// in this example, there is only one reference to each Employee,
		// so the following two statements cause the JVM to mark each
		// Employee object for garbage collection
		e1 = null;
		e2 = null;
		//After this point, if I call getCount(), I may get 0,1,2
		//I don't know which objects are deleted, I don't know if any object is deleted

		System.gc(); // ask for garbage collection to occur now
		//If I force the garbage collector to run, 
		//   all garbages (whose reference count is zero) are collected


		// show Employee count after calling garbage collector; count
		// displayed may be 0, 1 or 2 based on whether garbage collector
		// executes immediately and number of Employee objects collected
		System.out.printf( "\nEmployees after System.gc(): %d\n",
							Employee.getCount() );
	} // end main
} // end class EmployeeTest


/*

SAMPLE DIALOGUE
---------------
Employees before instantiation: 0
Employee constructor: Susan Baker; count = 1
Employee constructor: Bob Blue; count = 2

Employees after instantiation:
via e1.getCount(): 2
via e2.getCount(): 2
via Employee.getCount(): 2

Employee 1: Susan Baker
Employee 2: Bob Blue

Employee finalizer: Bob Blue; count = 1
Employee finalizer: Susan Baker; count = 0

Employees after System.gc(): 0

-------------------------------------------------
finalizers are called not by me, but by garbage collector

*/