/*---------------- 
Debanjan Saha
19CS30014
-----------------*/

// ***** C++ Standard Library Headers
#include<iostream>
#include<string>
using namespace std;

// ***** Project Headers
#include "Station.h"

//Default Constructor with empty string as name
Station::Station():name_("")
{}

//Constructor with one parameter
Station::Station(const string name): name_(name)
{}

string Station::GetName() const
{
    //return name of self(a Station)
    return name_;
}

int Station::GetDistance(const Station& otherStation) const
{
    // Gets distance from self to another Station from a method of Singleton Railways.
    return (Railways::IndianRailways()).GetDistance(name_,otherStation.GetName());
}

//Destructor
Station::~Station()
{}

// Output Stream Overloading
ostream& operator<<(ostream& os,const Station& station)
{
    os<<station.GetName();
    return os;
}

