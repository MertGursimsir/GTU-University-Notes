//This is the file salariedemployee.cpp
//This is the implementation for the class SalariedEmployee.
//The interface for the class SalariedEmployee is in
//the header file salariedemployee.h.
#include <iostream>
#include <string>
#include "salariedemployee.h"
using std::string;
using std::cout;
using std::endl;

namespace SavitchEmployees
{

    SalariedEmployee::SalariedEmployee( ) : Employee( ), salary(0)
    {
        //deliberately empty
        //since I am a Employee class, my constructor will call the constructor of the Employee
        //Employee constructor will handle data members come from the Employee
        //salary is new so I need to set it myself
    }

    SalariedEmployee::SalariedEmployee(const string&  newName, const string&  newNumber,
                                  double newWeeklyPay)
                     : Employee(newName, newNumber), salary(newWeeklyPay)
    {
        //deliberately empty
    }

    double SalariedEmployee::getSalary( ) const
    {
        return salary;
    }

    void SalariedEmployee::setSalary(double newSalary)
    {
        salary = newSalary;
    }

    void SalariedEmployee::printCheck( )
    {
        setNetPay(salary);
        cout << "\n__________________________________________________\n";
        cout << "Pay to the order of " << getName( ) << endl;
        cout << "The sum of " << getNetPay( ) << " Dollars\n";
        cout << "_________________________________________________\n";
        cout << "Check Stub NOT NEGOTIABLE \n";
        cout << "Employee Number: " << getSsn( ) << endl;
        cout << "Salaried Employee. Regular Pay: "
             << salary << endl;
        cout << "_________________________________________________\n";

        //Why don't we do name instead of getName()?
        //Because name is a private member of another class --> Employee
        //You cant modify private member of base class
    }
}//SavitchEmployees

