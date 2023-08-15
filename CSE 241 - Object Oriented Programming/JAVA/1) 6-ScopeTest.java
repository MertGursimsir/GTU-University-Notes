// Fig. 6.12: ScopeTest.java
// Application to test class Scope.

public class ScopeTest
{
	// application starting point
	public static void main( String args[] )
	{
		Scope testScope = new Scope();
		testScope.begin();
	} // end main
} // end class ScopeTest

/* 

SAMPLE DIALOGUE
---------------
local x in method begin is 5

local x on entering method useLocalVariable is 25
local x before exiting method useLocalVariable is 26

field x on entering method useField is 1
field x before exiting method useField is 10

local x on entering method useLocalVariable is 25
local x before exiting method useLocalVariable is 26

field x on entering method useField is 10
field x before exiting method useField is 100

local x in method begin is 5

*/