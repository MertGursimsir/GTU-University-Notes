//This is the header file salariedemployee.h.
//This is the interface for the class SalariedEmployee.
#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include <string>

using std::string;

namespace SavitchEmployees
{

    class SalariedEmployee
    {
    public:
        SalariedEmployee( );
        SalariedEmployee (const string&  theName, const string&  theSsn,
                                  double theWeeklySalary);
        
        
        string getName( ) const;
        string getSsn( ) const;
        double getNetPay( ) const;
        void setName(const string& newName);
        void setSsn(const string& newSsn);
        void setNetPay(double newNetPay);
        void printCheck( ) const;
        //all these functions are same as the employee class

        double getSalary( ) const;
        void setSalary(double newSalary);
    private:
        string name;
        string ssn;
        double netPay;
        double salary;//weekly
    };

}//SavitchEmployees

#endif //SALARIEDEMPLOYEE_H
