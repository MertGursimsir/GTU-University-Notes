//This is the header file dtime.h. This is the interface for the class DigitalTime.
//Values of this type are times of day. The values are input and output in 24 hour
//notation as in 9:30 for 9:30 AM and 14:45 for 2:45 PM.
#ifndef DTIME_H
#define DTIME_H
#include <iostream>
using std::istream;
using std::ostream;

namespace DTimeSavitch
{
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

        friend bool operator ==(const DigitalTime& time1, 
                                const DigitalTime& time2);
        friend istream& operator >>(istream& ins, DigitalTime& theObject);
        friend ostream& operator <<(ostream& outs, 
                                    const DigitalTime& theObject);
    private:
        int hour;
        int minute;

        //private functions that dont obey encapsulation rule is in the namespace now.
    };

} //DTimeSavitch


namespace
{
	int function1();
}
//RECALL: dtime.h is included both in dtime.cpp and timedemo.cpp
//What unnamed namespace does this belong to, dtime compilation unit or timedemo compilation unit?
//There are just 2 compilation unit: dtime.cpp and timedemo.cpp
//We don't compile dtime.h
//So which compilation unit we placed function1?
//Both dtime.cpp and timedemo.cpp
//Recall compilation unit is file along with all of its includes
//When I include dtime.h, it becomes part of my compilation unit
//So if I define unnamed namespace in dtime.h, anything 
// I put inside that unnamed namespace, will belong to the 
// unnamed namespace of dtime.cpp compilation unit and same for timedemo.cpp too
//Thats why we dont usually see unnamed namespaces in header files
//bc they will be included and it will belong to many other compilation unit


#endif //DTIME_H