//Program to demonstrate the class PFArrayD.
#include <iostream>
using namespace std;

//Objects of this class are partially filled arrays of doubles.
class PFArrayD
{
public:
    PFArrayD( );
    //Initializes with a capacity of 50.

    explicit PFArrayD(int capacityValue);
    //Lets say a function's parameter is PFArrayD and you send an integer to it
    //you can call that function with an integer because:
    //with this constructor you can convert integer to PFArrayD
    //WE DON'T WANT THIS BECAUSE IT IS NOT MEANINGFUL
    //you put explicit keyword at the beginning of this construct to prevent this



    //BE CAREFUL TO NOT TO FORGET &
    //IF YOU FORGET, THEN COPY CONSTRUCTOR WILL NEED A COPY OF THE OBJECT
    //THEN IT WILL CALL THE COPY CONSTRUCTOR AGAIN
    //IT WILL BE KIND OF AN INFINITE RECURSION
    //IT WILL CONTINUE UNTIL MY STACK IS FILLED UP
    PFArrayD(const PFArrayD& other);
    //If you put this copy constructor in you PRIVATE section, 
    //your customers cannot return PFArrayD objects from their functions or
    //they can't make a call by value with this class BUT
    //you can make call by reference with this class.



    void addElement(double element);
    //Precondition: The array is not full.
    //Postcondition: The element has been added.

    void popBack() { if (used > 0) used--; };

    bool full( ) const { return (capacity == used); }
    //Returns true if the array is full, false otherwise.

    int getCapacity( ) const { return capacity; }

    int getNumberUsed( ) const { return used; }

    void emptyArray( ){ used = 0; }
    //Empties the array.

    

    double& operator[](int index);
    //Read and change access to elements 0 through numberUsed - 1.

    PFArrayD& operator =(const PFArrayD& rightSide);

    ~PFArrayD( );
private:
    double *a; //for an array of doubles.
    int capacity; //for the size of the array.
    int used; //for the number of array positions currently in use.

};

void testPFArrayD( );
//Conducts one test of the class PFArrayD.

int main( )
{
    cout << "This program tests the class PFArrayD.\n";

    char ans;
    do
    {
        testPFArrayD( );
        cout << "Test again? (y/n) ";
        cin >> ans;
    }while ((ans == 'y') || (ans == 'Y'));

    return 0;
}

void testPFArrayD( )
{
    int cap;
    cout << "Enter capacity of this super array: ";
    cin >> cap;
    PFArrayD temp(cap);

    cout << "Enter up to " << cap << " nonnegative numbers.\n";
    cout << "Place a negative number at the end.\n";

    double next;
    cin >> next;
    while ((next >= 0) && (!temp.full( )))
    {
        temp.addElement(next);
        cin >> next;
    }

    cout << "You entered the following "
         << temp.getNumberUsed( ) << " numbers:\n";
    int index;
    int count = temp.getNumberUsed( );
    for (index = 0; index < count; index++)
        cout << temp[index] << " ";
    cout << endl;
    cout << "(plus a sentinel value.)\n";
}


PFArrayD::PFArrayD( ) :capacity(50), used(0)
{
    a = new double[capacity];
}
/*
OR YOU CAN DO LIKE THIS  --> delegate constructor call
PFArrayD::PFArrayD( ) :PFArrayD(50)
{   }
*/

PFArrayD::PFArrayD(int size) :capacity(size), used(0)
{
    a = new double[capacity];
}



//COPY CONSTRUCTOR --> copies another PFArrayD object into myself
//const is since I am not modifying the other object
//If you remove const, then you can't copy const PFArrayD objects
//with const, you can make copy of non-const objects too

//PFArrayD t2(temp);  --> temp is another PFArrayD object
//Actually without writing copy constructor, PFArrayD would be still available.
PFArrayD::PFArrayD(const PFArrayD& other)
  :capacity(other.getCapacity( )), used(other.getNumberUsed( ))
{
    a = new double[capacity];
    for (int i =0; i < used; i++)
        a[i] = other.a[i];
    	//a[i] = other[i];
    	//YOU CAN'T DO THIS (will not compile)
    	//because other[] operator has to return const double reference
    	//because other is const in the parameter of function

    	//If you have this function and implementation for the class in addition to:
    	//double& operator[](int index) const;
    	//then you would be fine:
    	/*
    	const double& operator[](int index) const;
    	const double& PFArrayD::operator[](int index) const
		{
		    if (index >= used)
		    {
		        cout << "Illegal index in PFArrayD.\n";
		        exit(0);
		    }

		    return a[index];
		}
		*/
    	//this is better solution than the first one


    	//this->operator[](i) = other[i];
    	//YOU CAN COMPILE AND RUN AS THIS
    	//but this is unnecessary
}

void PFArrayD::addElement(double element)
{
    if (used >= capacity)
    {
    	capacity *= 2;
        double * t = new double[capacity];
        for (int i = 0; i < used; ++i)
        	t[i] = a[i];
        delete [] a;
        //a = nullptr;  --> no need this bc one line after we assign a to t
        a = t;
    }
    a[used] = element;
    used++;
}

double& PFArrayD::operator[](int index)
{
    if (index >= used)
    {
        cout << "Illegal index in PFArrayD.\n";
        exit(0);
    }

    return a[index];
}

PFArrayD& PFArrayD::operator =(const PFArrayD& rightSide)
{
    if (capacity != rightSide.capacity)
    {
        delete [] a;
        a = new double[rightSide.capacity];
    }
    //we didn't check this in copy constructor
    //because i am a new object in PFArrayD class so no need to check


    capacity = rightSide.capacity;
    used = rightSide.used;
    for (int i = 0; i < used; i++)
        a[i] = rightSide.a[i];

    return *this;
    //I am returning myself as a reference so that I can do cascading assignment
    //a=b=c=d...;

    //You can return rightSide but in that case you should add const in front of the function
}

PFArrayD::~PFArrayD( )
{
    delete [] a;
}
//Whenever my object is deleted, compiler will take care of a, capacity, and used
//I need to take care of where a points to in heap, i need to delete it
//[] in delete means that "I'm deleting an array, call destructor of each element"
//If you have Money object as your member in class, it will be destructed automatically
