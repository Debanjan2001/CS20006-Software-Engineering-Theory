/*---------------- 
Debanjan Saha
19CS30014
-----------------*/

#include<iostream>
#include<map>
using namespace std;

#include "Railways.h"

map<const string,const Station*> Railways::sStations;
map<pair<const Station*,const Station*>,int> Railways::sDistStations;

Railways::Railways()
{
    sStations["Mumbai"] = new Station("Mumbai");
    sStations["Delhi"] = new Station("Delhi");
    sStations["Bangalore"] = new Station("Bangalore");
    sStations["Kolkata"] = new Station("Kolkata");
    sStations["Chennai"] = new Station("Chennai");

    sDistStations[make_pair(sStations["Mumbai"],sStations["Delhi"])] = 1447;

    sDistStations[make_pair(sStations["Mumbai"],sStations["Bangalore"])] = 981;

    sDistStations[make_pair(sStations["Mumbai"],sStations["Kolkata"])] = 2014;

    sDistStations[make_pair(sStations["Mumbai"],sStations["Chennai"])] = 1338;

    sDistStations[make_pair(sStations["Delhi"],sStations["Bangalore"])] = 2150;

    sDistStations[make_pair(sStations["Delhi"],sStations["Kolkata"])] = 1472;
    
    sDistStations[make_pair(sStations["Delhi"],sStations["Chennai"])] = 2180;

    sDistStations[make_pair(sStations["Bangalore"],sStations["Kolkata"])] = 1871;

    sDistStations[make_pair(sStations["Bangalore"],sStations["Chennai"])] = 350;

    sDistStations[make_pair(sStations["Kolkata"],sStations["Chennai"])] = 1659;
}

Railways::~Railways()
{
    map<const string,const Station*>::iterator it;

    for(it = sStations.begin(); it!= sStations.end(); ++it)
    {
        delete it->second;
    }
} 

const Station* Railways::GetStation(const string& stationName) const
{
    map<const string,const Station* >::iterator it;

    for(it = sStations.begin(); it != sStations.end() ; ++it)
    {
        if( it->first == stationName)
            return it->second;
    }

    return NULL;
}

int Railways::GetDistance(const string& from,const string& to) const
{
    const Station* source = GetStation(from);
    const Station* destination = GetStation(to);

    map<pair<const Station*,const Station*>,int>::iterator it;
    it = sDistStations.find(make_pair(source,destination));

    if( it == sDistStations.end() )
    {
        it = sDistStations.find(make_pair(destination,source));
    }

    int distance = it->second;
    return distance;

}

