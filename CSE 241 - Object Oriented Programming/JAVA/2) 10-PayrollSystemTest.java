// Fig. 10.9: PayrollSystemTest.java
// Employee hierarchy test program.

public class PayrollSystemTest
{
	public static void main( String args[] )
	{
		// create subclass objects
		SalariedEmployee salariedEmployee =
				new SalariedEmployee( "John", "Smith", "111-11-1111", 800.00 );
		HourlyEmployee hourlyEmployee =
				new HourlyEmployee( "Karen", "Price", "222-22-2222", 16.75, 40 );
		CommissionEmployee commissionEmployee =
				new CommissionEmployee("Sue", "Jones", "333-33-3333", 10000, .06 );
		BasePlusCommissionEmployee basePlusCommissionEmployee =
				new BasePlusCommissionEmployee("Bob", "Lewis", "444-44-4444", 5000, .04, 300 );

		System.out.println( "Employees processed individually:\n" );

		System.out.printf( "%s\n%s: $%,.2f\n\n",
			salariedEmployee, "earned", salariedEmployee.earnings() );
		System.out.printf( "%s\n%s: $%,.2f\n\n",
			hourlyEmployee, "earned", hourlyEmployee.earnings() );
		System.out.printf( "%s\n%s: $%,.2f\n\n",
			commissionEmployee, "earned", commissionEmployee.earnings() );
		System.out.printf( "%s\n%s: $%,.2f\n\n",
			basePlusCommissionEmployee, "earned", basePlusCommissionEmployee.earnings() );
		//earnings are polymorphic calls

		// create four-element Employee array (array of Employee references)
		Employee employees[] = new Employee[ 4 ];

		// initialize array with Employees
		employees[ 0 ] = salariedEmployee;
		employees[ 1 ] = hourlyEmployee;
		employees[ 2 ] = commissionEmployee;
		employees[ 3 ] = basePlusCommissionEmployee;

		System.out.println( "Employees processed polymorphically:\n" );

		// generically process each element in array employees
		for ( Employee currentEmployee : employees )
		{
			System.out.println( currentEmployee ); 
			// invokes toString during runtime
			//		bc compiler don't know which toString to call
			//		there are 6 toString --> Object + our 5 class

			// determine whether element is a BasePlusCommissionEmployee
			// similar to dynamic cast
			if ( currentEmployee instanceof BasePlusCommissionEmployee )
			{
				// downcast Employee reference to
				// BasePlusCommissionEmployee reference
				BasePlusCommissionEmployee employee = 
					( BasePlusCommissionEmployee ) currentEmployee;
				//This is downcasting
				//Upcasting is always ok but you should be careful about downcasting
				//only place where you use typecasting in JAVA

				double oldBaseSalary = employee.getBaseSalary();
				employee.setBaseSalary( 1.10 * oldBaseSalary );
				System.out.printf(
						"new base salary with 10%% increase is: $%,.2f\n",
						employee.getBaseSalary() );
			} // end if

			System.out.printf(
				"earned $%,.2f\n\n", currentEmployee.earnings() );
			
		} // end for

		// get type name of each object in employees array
		for ( int j = 0; j < employees.length; j++ )
			System.out.printf( "Employee %d is a %s\n", j,
				employees[ j ].getClass().getName() );
	} // end main
} // end class PayrollSystemTest


/*

SAMPLE DIALOGUE
---------------
Employees processed individually:

salaried employee: John Smith
social security number: 111-11-1111
weekly salary: $800.00
earned: $800.00

hourly employee: Karen Price
social security number: 222-22-2222
hourly wage: $16.75; hours worked: 40.00
earned: $670.00

commission employee: Sue Jones
social security number: 333-33-3333
gross sales: $10,000.00; commission rate: 0.06
earned: $600.00

base-salaried commission employee: Bob Lewis
social security number: 444-44-4444
gross sales: $5,000.00; commission rate: 0.04; base salary: $300.00
earned: $500.00

Employees processed polymorphically:

salaried employee: John Smith
social security number: 111-11-1111
weekly salary: $800.00
earned $800.00

hourly employee: Karen Price
social security number: 222-22-2222
hourly wage: $16.75; hours worked: 40.00
earned $670.00

commission employee: Sue Jones
social security number: 333-33-3333
gross sales: $10,000.00; commission rate: 0.06
earned $600.00

base-salaried commission employee: Bob Lewis
social security number: 444-44-4444
gross sales: $5,000.00; commission rate: 0.04; base salary: $300.00
new base salary with 10% increase is: $330.00
earned $530.00

Employee 0 is a SalariedEmployee
Employee 1 is a HourlyEmployee
Employee 2 is a CommissionEmployee
Employee 3 is a BasePlusCommissionEmployee

*/