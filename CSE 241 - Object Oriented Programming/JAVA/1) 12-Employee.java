// Fig. 8.12: Employee.java
// Static variable used to maintain a count of the number of
// Employee objects in memory.

public class Employee
{
	private String firstName;
	private String lastName;
	private static int count = 0; // number of objects in memory

	// initialize employee, add 1 to static count and
	// output String indicating that constructor was called
	public Employee( String first, String last )
	{
		firstName = first;
		lastName = last;
		//reference copies, no string copies

		count++; // increment static count of employees
		System.out.printf( "Employee constructor: %s %s; count = %d\n",
							firstName, lastName, count );
	} // end Employee constructor

	// subtract 1 from static count when garbage
	// collector calls finalize to clean up object;
	// confirm that finalize was called
	// finalize is protected in Object class so it is protected in Employee
	// destructors don't return anything but finalize returns void
	// INSIDE THE OBJECT CLASS, ALL THE METHODDS HAS TO BE REGULAR METHODS INCLUDING THEIR RETURN TYPES
	protected void finalize() // ---> overridden to default finalize in Object class
	{
		count--; // decrement static count of employees
		//Even if I consider an Employee dead, I am not using any employees,
		//  this count doesn't reach to 0 bc I don't know when the objects are deleted. 
		//	So finalize is not like the destructor.
		//	So count is not telling you exactly how many Employees are alive at that moment.
		//  EXCEPT IF YOU CALL GARBAGE COLLECTOR EXPLICITLY
		System.out.printf( "Employee finalizer: %s %s; count = %d\n",
							firstName, lastName, count );
	} // end method finalize

	// get first name
	public String getFirstName()
	{
		return firstName;
	} // end method getFirstName

	// get last name
	public String getLastName()
	{
		return lastName;
	} // end method getLastName

	// static class method to get static count value
	public static int getCount()
	{
		return count;
	} // end method getCount
} // end class Employee