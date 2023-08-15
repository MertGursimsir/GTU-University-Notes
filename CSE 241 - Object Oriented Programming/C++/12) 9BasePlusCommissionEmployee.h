// Fig. 13.21: BasePlusCommissionEmployee.h 
// BasePlusCommissionEmployee class derived from Employee. 
#ifndef BASEPLUS_H 
#define BASEPLUS_H 
 
#include "CommissionEmployee.h" // CommissionEmployee class definition 

//BasePlusCommissionEmployee inherits from CommissionEmployee
//BasePlusCommissionEmployee is already concrete
class BasePlusCommissionEmployee : public CommissionEmployee  
{ 
public: 
   BasePlusCommissionEmployee( const string &, const string &, 
      const string &, double = 0.0, double = 0.0, double = 0.0 ); 
   //First 3 goes to Employee, next 2 goes to CommissionEmployee, last one is mine
 
   void setBaseSalary( double ); // set base salary 
   double getBaseSalary() const; // return base salary 
    
   // keyword virtual signals intent to override
   // both function will be overridden                     
   virtual double earnings() const; // calculate earnings                 
   virtual void print() const; // print BasePlusCommissionEmployee object 
private: 
   double baseSalary; // base salary per week 
}; // end class BasePlusCommissionEmployee 
 
#endif // BASEPLUS_H