//This is the header file dtime.h. This is the interface for the class DigitalTime.
//Values of this type are times of day. The values are input and output in 24 hour
//notation as in 9:30 for 9:30 AM and 14:45 for 2:45 PM.
#include <iostream>
using namespace std;

class DigitalTime
{
public:
    DigitalTime(int theHour, int theMinute);
    DigitalTime( );
    //Initializes the time value to 0:00 (which is midnight).

    getHour( ) const;
    getMinute( ) const;
    void advance(int minutesAdded);
    //Changes the time to minutesAdded minutes later.

    void advance(int hoursAdded, int minutesAdded);
    //Changes the time to hoursAdded hours plus minutesAdded minutes later.


    //IT DOESN'T MATTER WHERE YOU PUT YOUR FRIEND FUNCTIONS (PUBLIC OR PRIVATE)
    //BETTER TO PUT PUBLIC SO THAT USER CAN READ THEM (AS GLOBAL FUNCTIONS), 
    //USER DON'T READ PRIVATE SECTION, HE/SHE NEEDS ONLY PUBLIC PART
    friend bool operator ==(const DigitalTime& time1, 
                            const DigitalTime& time2);
    //comparison function is as the global function, it takes 2 objects
    //there is no conversion constructor available 
    //so we won't be able to converting an integer to time, etc.
    //so no need to make this function global but book made it that way, keep this like as it is

    friend istream& operator >>(istream& ins, DigitalTime& theObject);

    friend ostream& operator <<(ostream& outs, const DigitalTime& theObject);

private:
  
    int hour;
    int minute;
 
 	//STATIC FUNCTIONS WILL NOT TOUCH ANYTHING INSIDE THIS CLASS DATA MEMBERS
 	//RECALL: STATIC FUNCTIONS CANNOT ACCESS NON-STATIC DATA MEMBERS AND FUNCTIONS
 	//THESE STATIC FUNCTIONS CANNOT CALL ANY PUBLIC FUNCTIONS
    static void readHour(int& theHour);
    //Precondition: Next input in to be read from the keyboard is 
    //a time in notation, like 9:45 or 14:45.
    //Postcondition: theHour has been set to the hour part of the time. 
    //The colon has been discarded and the next input to be read is the minute.

    static void readMinute(int& theMinute);
    //Reads the minute from the keyboard after readHour has read the hour.

    static int digitToInt(char c);
    //Precondition: c is one of the digits ’0’ through ’9’.
    //Returns the integer for the digit; that is, digitToInt(’3’) returns 3.
};
