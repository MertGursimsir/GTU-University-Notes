//This is the file: pfarraydbak.cpp. 
//This is the implementation of the class PFArrayDBak.
//The interface for the class PFArrayDBak is in the file pfarraydbak.h.
#include "pfarraydbak.h"
#include <iostream>
using std::cout;

PFArrayDBak::PFArrayDBak( ) : PFArrayD( ), usedB(0)
{
    b = new double[getCapacity( )];
    //b = new double[capacity];
    //You can do this too bc capacity is protected not private but
    //first one is better
}

PFArrayDBak::PFArrayDBak(int capacityValue) : PFArrayD(capacityValue), usedB(0)
{
    b = new double[getCapacity( )];
    //b = new double[capacityValue];
    //You can do this too but first one is better bc we understand that
    //base class's capacity is now my capacity
}

PFArrayDBak::PFArrayDBak(const PFArrayDBak& oldObject) 
              : PFArrayD(oldObject), usedB(0)
              //You see?
              //We sent PFArrayDBak object to PFArrayD
              //PFArrayDBak object behaves like PFArrayD
{	
	//a,capacity,used (all of the base class's members) 
	//are already copied by PFArrayD's copy constructor
    b = new double[getCapacity( )];
    usedB = oldObject.usedB;
    for (int i = 0; i < usedB; i++)
        b[i] = oldObject.b[i];

}

void PFArrayDBak::backup( )
{
	//my capacity will not change, so I am not gonna modify it
	//I don't even have capacity in PFArrayDBak
    usedB = getNumberUsed( );
    for (int i = 0; i < usedB; i++)
        b[i] = operator[](i);
    	//You can also do this: b[i] = a[i];
    	//but first one is better bc it uses public interface
    	//second one uses the protected data (a)
}

void PFArrayDBak::restore( )
{
#if 1
    emptyArray( );
    for (int i = 0; i < usedB; i++)
        addElement(b[i]);
#else
	used = usedB;
	for (int i = 0; i < usedB; i++)
		a[i] = b[i];
		
	//You can also do like this:
	//But first one is better bc it uses public interface
#endif
}

PFArrayDBak& PFArrayDBak::operator =(const PFArrayDBak& rightSide)
{
    PFArrayD::operator =(rightSide);
    //As you see assignment operator of base class is actually inherited
    // and I can call it

    if (getCapacity( ) != rightSide.getCapacity( ))
    {
        delete [] b;
        b = new double[rightSide.getCapacity( )];
    }

    usedB = rightSide.usedB;
    for (int i = 0; i < usedB; i++)
        b[i] = rightSide.b[i];

    return *this;
}

PFArrayDBak::~PFArrayDBak( )
{
    delete [] b;
    //YOU DON'T HAVE TO CALL BASE CLASS'S DESTRUCTOR, 
    // IT IS CALLED AUTOMATICALLY AFTER DERIVED CLASS'S CONSTRUCTOR

    //REMEMBER COMPOSITION, WE DON'T CALL THE DESTRUCTOR OF MY OBJECT 
    // THROUGH COMPOSITION
}




