// Fig. 13.25: fig13_25.cpp 
// Demonstrating downcasting and run-time type information. 
// NOTE: For this example to run in Visual C++ .NET,  
// you need to enable RTTI (Run-Time Type Info) for the project. 
#include <iostream> 
using std::cout; 
using std::endl; 
using std::fixed; 

#include <iomanip> 
using std::setprecision; 
   
#include <vector> 
using std::vector; 
 
#include <typeinfo> 
 
// include definitions of classes in Employee hierarchy 
#include "Employee.h" 
#include "SalariedEmployee.h"  
#include "HourlyEmployee.h" 
#include "CommissionEmployee.h"   
#include "BasePlusCommissionEmployee.h"  
 
int main() 
{ 
   // set floating-point output formatting 
   cout << fixed << setprecision( 2 );  

   // create vector of four base-class pointers 
   vector < Employee * > employees( 4 ); 
 
   // initialize vector with various kinds of Employees 
   employees[ 0 ] = new SalariedEmployee(               
      "John", "Smith", "111-11-1111", 800 );            
   employees[ 1 ] = new HourlyEmployee(                 
      "Karen", "Price", "222-22-2222", 16.75, 40 );     
   employees[ 2 ] = new CommissionEmployee(             
      "Sue", "Jones", "333-33-3333", 10000, .06 );      
   employees[ 3 ] = new BasePlusCommissionEmployee(     
      "Bob", "Lewis", "444-44-4444", 5000, .04, 300 );  
 
   // polymorphically process each element in vector employees 
   for ( size_t i = 0; i < employees.size(); i++ )  
   { 
      employees[ i ]->print(); // output employee information 
      cout << endl; 
 
 	  //DOWNCAST THE EMPLOYEE POINTER TO A BASEPLUSCOMISSIONEMPLOYEE POINTER
 	  //********************************************************************
      // downcast pointer                              
      BasePlusCommissionEmployee *derivedPtr =         
         dynamic_cast < BasePlusCommissionEmployee * > 
            ( employees[ i ] );
      //I am saying:
      //"Follow the employees[i] pointer"
      //"Find the object"
      //"If the object is a BasePlusCommissionEmployee object, 
      // give me the valid pointer, otherwise give me null"

      //Employee *derivedPtr = dynamic_cast < BasePlusCommissionEmployee * > ( employees[ i ] );
      //will compile bc dynamic cast will give you pointer for BPCE object.
      //Since Employee is the base class, there is "is a" relationship and it will work
      //but line 79 and next a few lines would give an error bc Employee doesn't have getBaseSalary and setBaseSalary

      /*
		I could have said:
		(BasePlusCommissionEmployee*)emp[i];
		then the pointer is forcefully converted to BasePlusCommissionEmployee pointer
        I know that in the array, some of them are not BPCE pointers
        so most of the time this code would be very bad.
      */   

      // determine whether element points to base-salaried  
      // commission employee 	   //determine if cast was successful
      if ( derivedPtr != nullptr ) // nullptr if not a BasePlusCommissionEmployee 
      { 
      	 //if cast was successful, modify base salary
         double oldBaseSalary = derivedPtr->getBaseSalary(); 
         cout << "old base salary: $" << oldBaseSalary << endl; 
         derivedPtr->setBaseSalary( 1.10 * oldBaseSalary ); 
         cout << "new base salary with 10% increase is: $"  
            << derivedPtr->getBaseSalary() << endl;
         //2 functions are not a polymorphic call
         //bc getBaseSalary and setBaseSalary are not virtual functions
      } // end if 
       
      cout << "earned $" << employees[ i ]->earnings() << "\n\n";
      //regular polymorphic call bc earnings is a virtual function

   } // end for    
  
   // release objects pointed to by vector’s elements 
   for ( size_t j = 0; j < employees.size(); j++ ) 
   { 
      // output class name                            
      cout << "deleting object of "                   
         << typeid( *employees[ j ] ).name() << endl; 
      //Use typeid and function name to display object types
      //*employees[j] returns an Employee reference

      //This will be possible if you turn on the RTTI flag of your compiler
      //(Run Time Type Information)
      //If this is off, then you don't keep that information in your objects
      //If you want save some space, turn off RTTI so you don't keep that information

      delete employees[ j ]; 
   } // end for 
 
   return 0; 
} // end main


/*

SAMPLE OUTPUT
-------------
salaried employee: John Smith 
social security number: 111-11-1111 
weekly salary: 800.00 
earned $800.00 
 
hourly employee: Karen Price 
social security number: 222-22-2222 
hourly wage: 16.75; hours worked: 40.00 
earned $670.00 
 
commission employee: Sue Jones 
social security number: 333-33-3333 
gross sales: 10000.00; commission rate: 0.06 
earned $600.00 
 
base-salaried commission employee: Bob Lewis 
social security number: 444-44-4444 
gross sales: 5000.00; commission rate: 0.04; base salary: 300.00 
old base salary: $300.00 
new base salary with 10% increase is: $330.00 
earned $530.00 
 
deleting object of class SalariedEmployee 
deleting object of class HourlyEmployee 
deleting object of class CommissionEmployee 
deleting object of class BasePlusCommissionEmployee 

*/