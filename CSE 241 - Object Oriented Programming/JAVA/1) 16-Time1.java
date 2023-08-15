// Fig. 8.18: Time1.java
// Time1 class declaration maintains the time in 24-hour format.
package com.deitel.jhtp6.ch08;
//I am saying that I have a new package or I have a package, I am contributing this package
//You may add more classes to this package as long as you say "package com.deitel.jhtp6.ch08;"
//   at the beginning.
//You have to import this package whenever you want to use Time1 class

//To be able to use those packages, you need to "import" them. Similar to using.

//If you didn't say "package com.deitel.jhtp6.ch08;", this code would go to unnamed package
//  like other classes we wrote so far
//In JAVA you don't have global package, you have unnamed package.

public class Time1
{
	private int hour; // 0 - 23
	private int minute; // 0 - 59
	private int second; // 0 - 59

	// set a new time value using universal time; perform
	// validity checks on the data; set invalid values to zero
	public void setTime( int h, int m, int s )
	{
		hour = ( ( h >= 0 && h < 24 ) ? h : 0 ); // validate hour
		minute = ( ( m >= 0 && m < 60 ) ? m : 0 ); // validate minute
		second = ( ( s >= 0 && s < 60 ) ? s : 0 ); // validate second
	} // end method setTime

	// convert to String in universal-time format (HH:MM:SS)
	public String toUniversalString()
	{
		return String.format( "%02d:%02d:%02d", hour, minute, second );
	} // end method toUniversalString

	// convert to String in standard-time format (H:MM:SS AM or PM)
	public String toString()
	{
		return String.format( "%d:%02d:%02d %s",
								( ( hour == 0 || hour == 12 ) ? 12 : hour % 12 ),
								minute, second, ( hour < 12 ? "AM" : "PM" ) );
	} // end method toString
} // end class Time1