// Fig. 9.10: BasePlusCommissionEmployee3.java
// BasePlusCommissionEmployee3 inherits from CommissionEmployee2 and has
// access to CommissionEmployee2's protected members.

public class BasePlusCommissionEmployee3 extends CommissionEmployee2
{
	private double baseSalary; // base salary per week

	// six-argument constructor
	public BasePlusCommissionEmployee3( String first, String last,
										String ssn, double sales, double rate, double salary )
	{
		super( first, last, ssn, sales, rate );
		//has to be first executable statement in your constructor
		//calling the constructor of superclass
		//instead of calling my constructor with "this" keyword,
		//  I am calling superclass's constructor with "super" keyword.

		setBaseSalary( salary ); // validate and store base salary
	} // end six-argument BasePlusCommissionEmployee3 constructor

	// set base salary
	public void setBaseSalary( double salary )
	{
		baseSalary = ( salary < 0.0 ) ? 0.0 : salary;
	} // end method setBaseSalary

	// return base salary
	public double getBaseSalary()
	{
		return baseSalary;
	} // end method getBaseSalary

	// calculate earnings
	public double earnings()
	{
		return baseSalary + ( commissionRate * grossSales );
		//You can also do:
		//  return getBaseSalary() + super.earnings();
	} // end method earnings

	// return String representation of BasePlusCommissionEmployee3
	public String toString()
	{
		return String.format(
				"%s: %s %s\n%s: %s\n%s: %.2f\n%s: %.2f\n%s: %.2f",
				"base-salaried commission employee", firstName, lastName,
				"social security number", socialSecurityNumber,
				"gross sales", grossSales, "commission rate", commissionRate,
				"base salary", baseSalary );
		//You can also do:
		//	return String.format("%s\n%s: %.2f",
		//						super, "base salary", baseSalary);
		//	);
		//super has toString method, compiler knows how to convert this superclass 
		//   to a string.
	
	} // end method toString
} // end class BasePlusCommissionEmployee3