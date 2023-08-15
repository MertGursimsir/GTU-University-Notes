// Fig. 10.1: PolymorphismTest.java
// Assigning superclass and subclass references to superclass and
// subclass variables.

public class PolymorphismTest
{
	//static methods are not late binding, they are early binding
	//for static methods, there are only classes no objects 
	public static void main( String args[] )
	{
		// assign superclass reference to superclass variable
		CommissionEmployee3 commissionEmployee = new CommissionEmployee3(
						"Sue", "Jones", "222-22-2222", 10000, .06 );

		// assign subclass reference to subclass variable
		BasePlusCommissionEmployee4 basePlusCommissionEmployee =
						new BasePlusCommissionEmployee4(
						"Bob", "Lewis", "333-33-3333", 5000, .04, 300 );

		// invoke toString on superclass object using superclass variable
		System.out.printf( "%s %s:\n\n%s\n\n",
						"Call CommissionEmployee3's toString with superclass reference ",
						"to superclass object", commissionEmployee.toString() );
						//late binding bc compiler doesn't know commissionEmployee points to a
						//  CommissionEmployee3 object or BasePlusCommissionEmployee4 object
						//I am calling with reference

		// invoke toString on subclass object using subclass variable
		System.out.printf( "%s %s:\n\n%s\n\n",
						"Call BasePlusCommissionEmployee4's toString with subclass",
						"reference to subclass object",
						basePlusCommissionEmployee.toString() );

		// invoke toString on subclass object using superclass variable
		CommissionEmployee3 commissionEmployee2 = basePlusCommissionEmployee;
		System.out.printf( "%s %s:\n\n%s\n",
						"Call BasePlusCommissionEmployee4's toString with superclass",
						"reference to subclass object", commissionEmployee2.toString() );
						//basePlusCommissionEmployee's toString method will be called

	} // end main
} // end class PolymorphismTest

/*

SAMPLE DIALOGUE
---------------
Call CommissionEmployee3's toString with superclass reference to superclass object:

commission employee: Sue Jones
social security number: 222-22-2222
gross sales: 10000.00
commission rate: 0.06

Call BasePlusCommissionEmployee4's toString with subclass reference to subclass object:

base-salaried commission employee: Bob Lewis
social security number: 333-33-3333
gross sales: 5000.00
commission rate: 0.04
base salary: 300.00

Call BasePlusCommissionEmployee4's toString with superclass reference to subclass object:

base-salaried commission employee: Bob Lewis
social security number: 333-33-3333
gross sales: 5000.00
commission rate: 0.04
base salary: 300.00

*/