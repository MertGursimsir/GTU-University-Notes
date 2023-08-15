//Program to demonstrate bidirectional and random access iterators.
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::vector<char>::iterator;

int main( )
{
    vector<char> container;

    container.push_back('A');
    container.push_back('B');
    container.push_back('C');
    container.push_back('D');   

    for (int i = 0; i < 4; i++)
        cout << "container[" << i << "] == " 
             << container[i] << endl;

    iterator p = container.begin( );
    
    cout << "The third entry is " << container[2] << endl;
    //This notation is specialized to vectors and arrays

    cout << "The third entry is " << p[2] << endl;
    cout << "The third entry is " << *(p + 2) << endl;
    //These two work for any random-access iterator
    //for list, there is no random-access
    //for single list, there is no random-access and no -- operator defined

    cout << "Back to container[0].\n";
    p = container.begin( );
    cout << "which has value " << *p << endl;

    cout << "Two steps forward and one step back:\n";
    p++;
    cout << *p << endl;
    p++;
    cout << *p << endl;
    p--;
    cout << *p << endl;

    return 0;
}
