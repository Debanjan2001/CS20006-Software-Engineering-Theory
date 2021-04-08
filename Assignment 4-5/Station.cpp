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
#include "Exceptions.h"

//Forward Declaration
class Bad_Station;

//Default Constructor with empty string as name
Station::Station():name_("")
{}

//Constructor with one parameter
Station::Station(const string& name): name_(name)
{}

string Station::GetName() const
{
    //return name of self(a Station)
    return name_;
}

const Station& Station::CreateStation(const string& name)
{
    const Station* station = (Railways::IndianRailways()).GetStation(name);
    try
    {
        if(station == NULL)
        {
            Bad_Station error;
            throw error;
        }
        else
        {
            return Station(station->GetName());
        }
    }
    catch(Bad_Station& error)
    {
        cout<<error.what()<<endl;
    }

    return Station(name);
}

int Station::GetDistance(const Station& otherStation) const
{
    // Gets distance from self to another Station from a method of Singleton Railways.
    return (Railways::IndianRailways()).GetDistance(name_,otherStation.GetName());
}

//Destructor
Station::~Station()
{}

//UnitTest
void Station::UnitTestStation()
{
    Station s1; // Station  with no parameter
    Station s2("Kolkata"); // Station with a user defined name
    Station s3("Delhi");

    if(s1.GetName().length()!=0)
        cout<<"  Station construction error on Station"<<endl;
    else
        cout<<"  Subtest-1 Passed" <<endl;

    if(s2.GetName() != "Kolkata")
        cout<<"  Station construction error on Station(\"Kolkata\")"<<endl;
    else
        cout<<"  Subtest-2 Passed" <<endl;

    if(s2.GetDistance(s3) != 1472)
        cout<<"  Station GetDistance error on Station(\"Kolkata\").GetDistance(Station(\"Delhi\"))"<<endl;
    else
        cout<<"  Subtest-3 Passed" <<endl;

}

// Output Stream Overloading
ostream& operator<<(ostream& os,const Station& station)
{
    os<<station.GetName();
    return os;
}

