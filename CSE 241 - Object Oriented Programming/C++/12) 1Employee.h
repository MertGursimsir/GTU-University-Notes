// Fig. 13.13: Employee.h 
// Employee abstract base class. 
#ifndef EMPLOYEE_H 
#define EMPLOYEE_H 
 
#include <string> // C++ standard string class 
using std::string; 
 
class Employee  
{ 
public: 
   Employee( const string &, const string &, const string & ); 
 
   void setFirstName( const string & ); // set first name 
   string getFirstName() const; // return first name 
 
   void setLastName( const string & ); // set last name 
   string getLastName() const; // return last name 
 
   void setSocialSecurityNumber( const string & ); // set SSN 
   string getSocialSecurityNumber() const; // return SSN 

   // pure virtual function makes Employee abstract base class 
   virtual double earnings() const = 0; // pure virtual        
   //earnings is pure virtual, not enough data to provide a default, concrete implementation
   virtual void print() const; // virtual
   //print is virtual, default implementation provided but derived-classes may override                

   //So I will make decision for earnings and print function calls during runtime
private: 
   string firstName; 
   string lastName; 
   string socialSecurityNumber; 
}; // end class Employee 
 
#endif // EMPLOYEE_H 