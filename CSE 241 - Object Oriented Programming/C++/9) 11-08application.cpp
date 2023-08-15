//This is the application file: timedemo.cpp which demonstrates use of DigitalTime.
#include <iostream>
using namespace std;

#include "dtime.h"
using namespace DTimeSavitch;

//namespace of main is global and it has to be global namespace
//otherwise compiler cannot produce an executable code
int main( )
{
    DigitalTime clock, oldClock;
    //When I say DigitalTime, compiler smart enough 
    //to scan std namespace to see if there are any definitions from there, it is not there
    //then it looks DTimeSavitch if it is there it uses it
    //if it is not there it checks the global namespace
    //if it can't find there too, then it gives error

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
