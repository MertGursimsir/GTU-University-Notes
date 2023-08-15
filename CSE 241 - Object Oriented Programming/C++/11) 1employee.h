//This is the header file employee.h.
//This is the interface for the class Employee.
//This is primarily intended to be used as a base class to derive
//classes for different kinds of employees.
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using std::string;

namespace SavitchEmployees
{

    class Employee
    {
    public:
        Employee( );
        Employee(const string& theName, const string& theSsn);
        string getName( ) const;
        string getSsn( ) const;
        double getNetPay( ) const;
        void setName(const string& newName);
        void setSsn(const string& newSsn);
        void setNetPay(double newNetPay);

        void printCheck( ) const;
        //printCheck will always be redefined in derived class
        //So why we write printCheck for Employee class?
        // 1--> Force the user do not use Employee class
        //      You are signaling the user that Employee is not a
        //		class to be instantiated, it is base class.
        // 2--> Let's say you have this function:
        //		void f(Employee * p){
        //			p -> setName("ABC");
        //			p -> printCheck();
        //		}
        //		with this function, salariademployee pointers will work,
        //		hourly employee pointers will work, employee pointers
        //		will work but we don't use the employee objects anyway
        //		This function tells me whatever employee object
        //		(salariad,hourly...etc), this code will work.
        //		BUT for this code to compile, I need to have printCheck
        //		function in Employee class 
        //		I know that printCheck is not meaningful for Employee
        //		class but it will be meaningful for the future classes
        //FOR printCheck function, I am inheriting only the interface
        //it is not my intention to inherit the implementation of printCheck

        //We will do this:
        //void printCheck() const = 0;
        //This means I am not going to implement this func
        //It is meaningless to implement, but meaningful to have in my interface
        //so that any class derives from employee will have to implement it
    	//These functions are called ABSTRACT FUNCTIONS
    	//They are intended to be parts of the interface but 
    	//they are not supposed to be implemented and compiler knows about it
    	//if you try to implement this func, compiler will give you an error message
    	//if you try to make an object of class Employee, compiler will tell no you are not allowed.
    	//So when I create a derived class, I just inherit the interface, not implementation
    	
    
    private:
        string name;
        string ssn; //social security number (tc kimlik numarası gibi)
        double netPay;
    };

}//SavitchEmployees

#endif //EMPLOYEE_H
