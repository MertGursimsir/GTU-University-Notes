//This is the header file pfarraydbak.h. This is the interface for the class 
//PFArrayDBak. Objects of this type are partially filled arrays of doubles.
//This version allows the programmer to make a backup copy and restore
//to the last saved copy of the partially filled array.
#ifndef PFARRAYDBAK_H
#define PFARRAYDBAK_H
#include "pfarrayd.h"

class PFArrayDBak : public PFArrayD
{
public:
    PFArrayDBak( );
    //Initializes with a capacity of 50.

    explicit PFArrayDBak(int capacityValue);

    PFArrayDBak(const PFArrayDBak& Object);
    //If I don't define this copy constructor, default one will be used
    //default one is memberwise copy and we don't want it bc we have pointer
    //Same for assignment operator

    PFArrayDBak& operator =(const PFArrayDBak& rightSide);

    ~PFArrayDBak( );



    void backup( );
    //Makes a backup copy of the partially filled array.

    void restore( );
    //Restores the partially filled array to the last saved version. 
    //If backup has never been invoked, this empties the partially filled array.

    
private:
    double *b; //for a backup of main array.
    int usedB; //backup for inherited member variable used.
};

#endif //PFARRAYD_H

/*
 ________________
|		 | used  |
|PFARRAYD| cap   |
|		 | a  	 |
|________|_______|
| 	   usedB	 |
| 		 b 		 |
|________________|
 

Why don't we just use "PFArrayD b;" instead of usedB and b?
-----------------------------------------------------------
Then we have both isA and hasA (composition) relationship.
isA : arrow goes from PFArrayDBak to PFArrayD
hasA: arrow goes from PFArrayD to PFArrayDBak

Then we have the PFArrayDBak's private section as this (others remains same):
PFArrayD b;

Then you don't need big three for PFArrayDBak.
Memberwise copy will work fine.
Default assignment operator calls assignment operators of all the data members it has.
Actually that's why it is dangerous to do memberwise copy between two pointers
 bc it just copies the pointer not deep copying
Assignment from PFArrayD to some other PFArrayD will be handled nicely.


//HEADER
class PFArrayDBak : public PFArrayD
{
public:
	//Default copy const, destructor, asgn operator are okay
    PFArrayDBak( );
    explicit PFArrayDBak(int capacityValue);
    void backup( );
    void restore( );
private:
    PFArrayD b;
};

//IMPLEMENTATION
PFArrayDBak::PFArrayDBak( ) : PFArrayD( ), b(0)
{ We said b(0) bc we aren't using memory for now, we'll use for backup }

PFArrayDBak::PFArrayDBak(int capacityValue) : PFArrayD(capacityValue), b(0)
{ }

void PFArrayDBak::backup( )
{
    b = *this;
    //This will work bc PFArrayDBak is PFArrayD
    //b 	: PFArrayD
    //*this : PFArrayDBak


    //If your private member is "vector <PFArrayD> b;" which stores multiple backups,
    //then you can do backup function like this:
    //b.push_back(*this);

}

void PFArrayDBak::restore( )
{
    //*this = b;  
    //This will not work bc PFArrayD is not PFArrayDBak and *this is constant

	emptyArray( );
    for (int i = 0; i < getUsed(); i++)
        addElement(b[i]);


    //If your private member is "vector <PFArrayD> b;" which stores multiple backups,
    //then you can do restore function like this :
    //void PFArrayDBak::restore(int j){
    //	emptyArray();
	//	for (int i = 0; i < b[j].getUsed(); i++)
    //	  addElement(b[j][i]);
    //}
} 

 */