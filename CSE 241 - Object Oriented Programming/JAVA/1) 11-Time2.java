// Fig. 8.5: Time2.java
// Time2 class declaration with overloaded constructors.

public class Time2
{
	private int hour; // 0 - 23
	private int minute; // 0 - 59
	private int second; // 0 - 59

	// Time2 no-argument constructor: initializes each instance variable
	// to zero; ensures that Time2 objects start in a consistent state
	public Time2()
	{
		this( 0, 0, 0 ); // invoke Time2 constructor with three arguments
		//we would do like this in C++ --> Time2():hour(0), minute(0), second(0)
	} // end Time2 no-argument constructor

	// Time2 constructor: hour supplied, minute and second defaulted to 0
	public Time2( int h )
	{
		this( h, 0, 0 ); // invoke Time2 constructor with three arguments
	} // end Time2 one-argument constructor

	// Time2 constructor: hour and minute supplied, second defaulted to 0
	public Time2( int h, int m )
	{
		this( h, m, 0 ); // invoke Time2 constructor with three arguments
	} // end Time2 two-argument constructor
	// Time2 constructor: hour, minute and second supplied
	public Time2( int h, int m, int s )
	{
		setTime( h, m, s ); // invoke setTime to validate time
	} // end Time2 three-argument constructor

	// Time2 constructor: another Time2 object supplied
	public Time2( Time2 time )
	{
		// invoke Time2 three-argument constructor
		this( time.getHour(), time.getMinute(), time.getSecond() );
	} // end Time2 constructor with a Time2 object argument

	// Set Methods
	// set a new time value using universal time; ensure that
	// the data remains consistent by setting invalid values to zero
	public void setTime( int h, int m, int s )
	{
		setHour( h ); // set the hour
		setMinute( m ); // set the minute
		setSecond( s ); // set the second
	} // end method setTime
} // end class Time2