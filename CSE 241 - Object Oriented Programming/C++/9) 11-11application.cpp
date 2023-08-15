//This is the application file: timedemo.cpp which demonstrates use of DigitalTime.
#include <iostream>
using namespace std;

#include "dtime.h"
using namespace DTimeSavitch;
//As you see including dtime.h doesn't make the namespace DTimeSavitch available for me.
//If you like to use anything in the namespace, you must say so.

int main( )
{
    DigitalTime clock, oldClock;
    //If you use line 6, you can still do like this:
    //	  DTimeSavitch::DigitalTime clock, oldClock;
    //We are saying that "for DigitalTime class, you don't have to look global or std namespaces,
    //DigitalTime class is available at DTimeSavitch namespace."
    //Dont do this

    //If you don't use line 6, you can say like this:
    //    DTimeSavitch::DigitalTime clock, oldClock;
    //	  type of clock is DTimeSavitch::DigitalTime
    //Under this situation, when the compiler checks "clock.advance(15);", it knows that clock belongs to
    //DigitalTime class which belongs to DTimeSavitch namespace 

    cout << "You may write midnight as either 0:00 or 24:00,\n"
         << "but, I will always write it as 0:00.\n"
         << "Enter the time in 24 hour notation: ";
    cin >> clock;

    oldClock = clock;
    clock.advance(15);
    if (clock == oldClock)
        cout << "Something is wrong.";
    cout << "You entered " << oldClock << endl;
    cout << "15 minutes later the time will be "
         << clock << endl;

    clock.advance(2, 15);
    cout << "2 hours and 15 minutes after that\n"
         << "the time will be "
         << clock << endl;

    return 0;
}
