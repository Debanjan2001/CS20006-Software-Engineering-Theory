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
map<const string,bool> Railways::sStations;
map<pair<const string,const string>,int> Railways::sDistStations;

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

int Railways::GetDistance(const string from,const string to) const
{
    
    // Gets distance between the two Stations
    map<pair<const string,const string>,int>::iterator it;
    it = sDistStations.find(make_pair(from,to));

    if( it == sDistStations.end() )
    {
        it = sDistStations.find(make_pair(to,from));
    }

    int distance = it->second;
    return distance;
}

void Railways::AddStation(const string station)
{
    try
    {
        if(sStations.find(station) == sStations.end())
            sStations[station] = true;
        else
            throw Bad_Railways("Exception! Duplication of Station Not Allowed");
    }
    catch(const Bad_Railways& e)
    {
               cout<<e.what()<<endl;;
    }
    
}


void Railways::AddDistance(const string station1,const string station2,int distance)
{
    try
    {
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
