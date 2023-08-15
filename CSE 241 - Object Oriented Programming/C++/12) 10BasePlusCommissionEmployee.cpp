// Fig. 13.22: BasePlusCommissionEmployee.cpp 
// BasePlusCommissionEmployee member-function definitions. 
#include <iostream> 
using std::cout; 
 
// BasePlusCommissionEmployee class definition 
#include "BasePlusCommissionEmployee.h" 
 
// constructor  
BasePlusCommissionEmployee::BasePlusCommissionEmployee(  
   const string &first, const string &last, const string &ssn,  
   double sales, double rate, double salary ) 
   : CommissionEmployee( first, last, ssn, sales, rate )
   	 //We call CommissionEmployee constructor which in turns call the Employee constructor
{ 
   setBaseSalary( salary ); // validate and store base salary 
} // end BasePlusCommissionEmployee constructor 
 
// set base salary 
void BasePlusCommissionEmployee::setBaseSalary( double salary ) 
{  
   baseSalary = ( ( salary < 0.0 ) ? 0.0 : salary );  
} // end function setBaseSalary 
 
// return base salary 
double BasePlusCommissionEmployee::getBaseSalary() const 
{  
    return baseSalary;  
} // end function getBaseSalary 

// calculate earnings; 
// override pure virtual function earnings in Employee 
double BasePlusCommissionEmployee::earnings() const 
{  
    return getBaseSalary() + CommissionEmployee::earnings();  
} // end function earnings 
 
// print BasePlusCommissionEmployee's information  
void BasePlusCommissionEmployee::print() const 
{ 
   cout << "base-salaried "; 
   CommissionEmployee::print(); // code reuse 
   cout << "; base salary: " << getBaseSalary(); 
} // end function print