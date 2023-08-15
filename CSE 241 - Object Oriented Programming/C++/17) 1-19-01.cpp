//Program to demonstrate STL iterators.
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::vector<int>::iterator;
//iterator is an inner class inside the vector int

int main( )
{
    vector<int> container;

    for (int i = 1; i <= 4; i++)
        container.push_back(i);

    cout << "Here is what is in the container:\n";
    iterator p;

    //you can use auto for p in for loop --> auto p = container.begin()
    //with this way you can use list or vector or sth else with same code
    //   without line 7 and 18 (without using std::vector<int>::iterator)
    for (p = container.begin( ); p != container.end( ); p++)
        cout << *p << " ";
    cout << endl;

    cout << "Setting entries to 0:\n";
    for (p = container.begin( ); p != container.end( ); p++)
         *p = 0;
    cout << "Container now contains:\n";
 
    for (p = container.begin( ); p != container.end( ); p++)
        cout << *p << " ";
    cout << endl;

    return 0;
}
