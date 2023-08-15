//Program to demonstrate use of the map template class.
#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::endl;
using std::map;
using std::string;

int main( )
{
    map<string, string> planets;

    planets["Mercury"] = "Hot planet";
    planets["Venus"] = "Atmosphere of sulfuric acid";
    planets["Earth"] = "Home";
    planets["Mars"] = "The Red Planet";
    planets["Jupiter"] = "Largest planet in our solar system";
    planets["Saturn"] = "Has rings";
    planets["Uranus"] = "Tilts on its side";
    planets["Neptune"] = "1500 mile per hour winds";
    planets["Pluto"] = "Dwarf planet";

    cout << "Entry for Mercury - " << planets["Mercury"] 
	    << endl << endl;

	//if find() finds it, returns an iterator to that position
	//if doesn't find it, returns an iterator to planets.end() iterator position
    if (planets.find("Mercury") != planets.end())
    	cout << "Mercury is in the map." << endl;
    if (planets.find("Ceres") == planets.end())
    	cout << "Ceres is not in the map." << endl << endl;

    // Iterator outputs planets in order sorted by key alphabetically
    cout << "Iterating through all planets: " << endl;
    map<string, string>::const_iterator iter;
    for (iter = planets.begin(); iter != planets.end(); iter++)
    {
	   cout << iter->first << " - " << iter->second << endl;
    }

    return 0;
}