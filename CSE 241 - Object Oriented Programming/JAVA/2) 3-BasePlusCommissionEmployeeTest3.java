// Fig. 9.11: BasePlusCommissionEmployeeTest3.java
// Testing class BasePlusCommissionEmployee3.

public class BasePlusCommissionEmployeeTest3
{
	public static void main( String args[] )
	{
		// instantiate BasePlusCommissionEmployee3 object
		BasePlusCommissionEmployee3 employee =
				new BasePlusCommissionEmployee3(
				"Bob", "Lewis", "333-33-3333", 5000, .04, 300 );
		//If I do:
		//	CommissionEmployee employee = 
		//		new BasePlusCommissionEmployee3(
		//		"Bob", "Lewis", "333-33-3333", 5000, .04, 300 );
		//You won't get an error message
		//	bc BasePlusCommissionEmployee3 "isA" CommissionEmployee
		//There is no slicing but I can't reach baseSalary

		// get base-salaried commission employee data
		System.out.println(
			"Employee information obtained by get methods: \n" );
		System.out.printf( "%s %s\n", "First name is",
			employee.getFirstName() );
		System.out.printf( "%s %s\n", "Last name is",
			employee.getLastName() );
		System.out.printf( "%s %s\n", "Social security number is",
			employee.getSocialSecurityNumber() );
		System.out.printf( "%s %.2f\n", "Gross sales is",
			employee.getGrossSales() );
		System.out.printf( "%s %.2f\n", "Commission rate is",
			employee.getCommissionRate() );
		System.out.printf( "%s %.2f\n", "Base salary is",
			employee.getBaseSalary() );
		//employee.getBaseSalary() will not work if you do:
		//	CommissionEmployee employee = 
		//		new BasePlusCommissionEmployee3(
		//		"Bob", "Lewis", "333-33-3333", 5000, .04, 300 );

		employee.setBaseSalary( 1000 ); // set base salary

		System.out.printf( "\n%s:\n\n%s\n",
							"Updated employee information obtained by toString",
							employee.toString() ); //you can simply say "employee"
												   //instead of "employee.toString()"
												   //compiler knows how to convert it to string

	} // end main
} // end class BasePlusCommissionEmployeeTest3

/*

SAMPLE DIALOGUE
---------------
Employee information obtained by get methods:
First name is Bob
Last name is Lewis
Social security number is 333-33-3333
Gross sales is 5000.00
Commission rate is 0.04
Base salary is 300.00
Updated employee information obtained by toString:
base-salaried commission employee: Bob Lewis
social security number: 333-33-3333
gross sales: 5000.00
commission rate: 0.04
base salary: 1000.00

*/