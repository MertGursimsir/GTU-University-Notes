//This is the file: hourlyemployee.cpp
//This is the implementation for the class HourlyEmployee.
//The interface for the class HourlyEmployee is in
//the header file hourlyemployee.h.
#include <string>
#include <iostream>
#include "hourlyemployee.h"
using std::string;
using std::cout;
using std::endl;

namespace SavitchEmployees
{

    HourlyEmployee::HourlyEmployee( ) 
    	: Employee( ), wageRate(0), hours(0)
    	//If I don't write the code in line 16, code still works and also
    	//compiler will call the no parameter/default constructor of the base class
    	//So if you don't call the base class's constructor, 
    	//compiler will automatically call the base class's no parameter constructor
    //Writing this instead of the above code:
    //HourlyEmployee::HourlyEmployee( ) 
    //	: wageRate(0), hours(0)
    //is exactly the same thing but DON'T DO THIS
    //ALWAYS CALL ONE OF THE BASE CLASS'S CONSTRUCTORS
    {
        //deliberately empty
    }

    HourlyEmployee::HourlyEmployee(const string&  theName, const string&  theNumber,
                                   double theWageRate, double theHours)
        : Employee(theName, theNumber), wageRate(theWageRate), hours(theHours)
    	//Same is here too, if you don't write line 32
    	//compiler will still call the base class's no parameter constructor
    {
        //deliberately empty
    }

    void HourlyEmployee::setRate(double newWageRate)
    {
        wageRate = newWageRate;
    }

    double HourlyEmployee::getRate( ) const
    {
        return wageRate;
    }

    void HourlyEmployee::setHours(double hoursWorked)
    {
        hours = hoursWorked;
    }

    double HourlyEmployee::getHours( ) const
    {
        return hours;
    }

    void HourlyEmployee::printCheck( )
    {
        setNetPay(hours * wageRate);

        //YOU CAN DO:
        //Employee::printCheck();

        cout << "\n________________________________________________\n";
        cout << "Pay to the order of " << getName( ) << endl;
        cout << "The sum of " << getNetPay( ) << " Dollars\n";
        cout << "________________________________________________\n";
        cout << "Check Stub: NOT NEGOTIABLE\n";
        cout << "Employee Number: " << getSsn( ) << endl;
        cout << "Hourly Employee. \nHours worked: " << hours
             << " Rate: " << wageRate << " Pay: " << getNetPay( ) << endl;
        cout << "_________________________________________________\n";
    }


}//SavitchEmployees




