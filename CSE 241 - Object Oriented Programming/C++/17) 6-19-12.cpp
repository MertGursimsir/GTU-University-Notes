//Program to demonstrate use of the set template class.
#include <iostream>
#include <set>
using std::cout;
using std::endl;
using std::set;

int main( )
{
    set<char> s;

    s.insert('A');
    s.insert('D');
    s.insert('D');
    s.insert('C');
    s.insert('C');
    s.insert('B');

    cout << "The set contains:\n";
    set<char>::const_iterator p;
    for (p = s.begin( ); p != s.end( ); p++)
        cout << *p << " ";
    cout << endl;

    cout << "Set contains 'C': ";
    if (s.find('C')==s.end( ))   //find returns an iterator
	   cout << " no " << endl;
    else
	   cout << " yes " << endl;

    cout << "Removing C.\n";
    s.erase('C');
    for (p = s.begin( ); p != s.end( ); p++)
        cout << *p << " ";
    cout << endl;

    cout << "Set contains 'C': ";
    if (s.find('C')==s.end( ))
	   cout << " no " << endl;
    else
	   cout << " yes " << endl;

    return 0;
}

/*

SAMPLE DIALOGUE
---------------
The set contains:
A B C D
Set contains 'C': yes
Removing C.
A B D
Set contains 'C': no

*/