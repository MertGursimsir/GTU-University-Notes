//This is the application file: timedemo.cpp. This program.
//demonstrates hiding the helping functions in an unnamed namespace.

#include <iostream>
#include "dtime.h"

void readHour(int& theHour); //global namespace


//There is an unnamed namespace in this file too but we didn't use it.

int main( )
{
    using std::cout;
    using std::cin;
    using std::endl;

    using DTimeSavitch::DigitalTime;

    int theHour;
    readHour(theHour);
    //This calls readHour that is defined in line 7 in this file
    //You cannot call readHour in unnamed namespace in dtime.cpp
    //If you like to call readHour in dtime.cpp, how you call it with unnamed namespace?
    //There is no way that you can specify

    DigitalTime clock(theHour, 0), oldClock;

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

void readHour(int& theHour)
{
    using std::cout;
    using std::cin;

    cout << "Let's play a time game.\n"
         << "Let's pretend the hour has just changed.\n"
         << "You may write midnight as either 0 or 24,\n"
         << "but, I will always write it as 0.\n"
         << "Enter the hour as a number (0 to 24): ";
    cin >> theHour;
}
