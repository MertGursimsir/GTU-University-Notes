//This is the header file salariedemployee.h.
//This is the interface for the class SalariedEmployee.
#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include <string>
#include "employee.h"

using std::string;

namespace SavitchEmployees
{

    //SalariadEmployee is same as class Employee
    //I am inheriting all the things from class employee and add new features
    //Only difference is I have 2 more functions (getSalary and setSalary)
    //and 1 more private data member
    //and I am going to change printCheck
    class SalariedEmployee : public Employee
    {
    public:
        SalariedEmployee( );
        SalariedEmployee (const string&  theName, const string&  theSsn,
                                  double theWeeklySalary);

        double getSalary( ) const;
        void setSalary(double newSalary);
        void printCheck( );
        //Overrides the printCheck func implementation from employee class
    private:
        double salary;//weekly
    };

}//SavitchEmployees

#endif //SALARIEDEMPLOYEE_H
