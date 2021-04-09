/*---------------- 
Debanjan Saha
19CS30014
-----------------*/

// ***** C++ Standard Library Headers
#include<iostream>
#include<map>
using namespace std;

// ***** Project Headers
#include "Railways.h"
#include "Exceptions.h"

// ***** Static definitions
map<const string,const Station*> Railways::sStations;
map<pair<const Station*,const Station*>,int> Railways::sDistStations;

// Implementation of Railways
Railways::Railways()
{
    // Predefined data
    AddStation("Mumbai");
    AddStation("Delhi");
    AddStation("Bangalore");
    AddStation("Kolkata");
    AddStation("Chennai");

    AddDistance("Mumbai","Delhi",1447);
    AddDistance("Mumbai","Bangalore",981);
    AddDistance("Mumbai","Kolkata",2014);
    AddDistance("Mumbai","Chennai",1338);
    AddDistance("Delhi","Banglore",2150);
    AddDistance("Delhi","Kolkata",1472);
    AddDistance("Delhi","Chennai",2180);
    AddDistance("Bangalore","Kolkata",1871);
    AddDistance("Bangalore","Chennai",350);
    AddDistance("Kolkata","Chennai",1659);
}

// Destructor
Railways::~Railways()
{
} 

const Station* Railways::GetStation(const string& stationName) const
{
    // Looks for a Station with matching name 
    map<const string,const Station* >::iterator it;

    for(it = sStations.begin(); it != sStations.end() ; ++it)
    {
        if( it->first == stationName)
            return (it->second);
    }

    // returns NULL if Station with given name is not found.
    return NULL;
}

const int Railways::GetDistance(const string& from,const string& to) const
{
    // Get source and destination stations from their names.
    const Station* source = GetStation(from);
    const Station* destination = GetStation(to);

    // Gets distance between the two Stations
    map<pair<const Station*,const Station*>,int>::iterator it;
    it = sDistStations.find(make_pair(source,destination));

    if( it == sDistStations.end() )
    {
        it = sDistStations.find(make_pair(destination,source));
    }

    int distance = it->second;
    return distance;
}

void Railways::AddStation(const string& station)
{
    try
    {
        if(sStations.find(station) == sStations.end())
            sStations[station] = &Station::CreateStation(station);
        else
            throw Bad_Railways("Exception! Duplication of Station Not Allowed");
    }
    catch(const Bad_Railways& e)
    {
        cout<<e.what()<<endl;;
    }
    
}



void Railways::AddDistance(const string& from,const string& to,int distance)
{
    try
    {
        const Station *station1 = GetStation(from);
        const Station *station2 = GetStation(to); 


        if(sDistStations.find(make_pair(station1,station2)) == sDistStations.end())
        {
            if(sDistStations.find(make_pair(station2,station1)) == sDistStations.end())
                sDistStations[make_pair(station1,station2)] = distance;
            else
                throw Bad_Railways("Exception occured! Distance already exists. ");
        }
        else
            throw Bad_Railways("Exception occured! Distance already exists. ");

    }
    catch(const Bad_Railways& e)
    {
        cout<<e.what()<<endl;;
    }
    
}
