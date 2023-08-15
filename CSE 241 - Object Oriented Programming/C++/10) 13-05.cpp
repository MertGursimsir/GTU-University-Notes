// Recursive program to determine if a string has an even number of 1's.
#include <iostream>
#include <string>

using namespace std;

// Function prototypes
bool evenNumberOfOnes(string s);
bool oddNumberOfOnes(string s);

// If the recursive calls end here with an empty string
// then we had an even number of 1's.
bool evenNumberOfOnes(string s)
{
	if (s.length() == 0)
		return true; // Is even
	else if (s[0]=='1')
		return oddNumberOfOnes(s.substr(1));  //s.substr(1) is same as s+1
		//if there are odd number of ones for s+1 string and my first letter is 1,
		//then there are even number of ones in the string
	else
		return evenNumberOfOnes(s.substr(1));
		//if there are even number of ones for s+1 string and my first letter is not 1,
		//then there are even number of ones in the string
}
//This function was not tail recursive bc it has 2 recursive cases
//but if the compiler smart enough, it can convert this to a tail recursive function.

// if the recursive calls end up here with an empty string
// then we had an odd number of 1's.
bool oddNumberOfOnes(string s)
{
	if (s.length() == 0)
		return false;	// Not even
	else if (s[0]=='1')
		return evenNumberOfOnes(s.substr(1));
		//if there are even number of ones for s+1 string and my first letter is 1,
		//then there are odd number of ones in the string
	else
		return oddNumberOfOnes(s.substr(1));
		//if there are odd number of ones for s+1 string and my first letter is not 1,
		//then there are odd number of ones in the string
}

int main()
{
	string s = "10011";

	if (evenNumberOfOnes(s))
		cout << "Even number of ones." << endl;
	else
		cout << "Odd number of ones." << endl;

	return 0;
}