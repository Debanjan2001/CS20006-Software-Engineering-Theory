/*---------------- 
Debanjan Saha
19CS30014
-----------------*/

// Start of "Railways.h"
#ifndef __RAILWAYS_H
#define __RAILWAYS_H

// ***** C++ Standard Library Headers
#include<iostream>
#include<string>
#include<map>
using namespace std;

// ***** Project Headers
#include "Station.h"

// Forward declaration
class Station;

// Singleton Class Railways
class Railways
{
    private:

        // List of Station as name-Station pairs
        static map<const string,const Station*> sStations;

        // List of distance between a pair of Stations as Station-Station pairs
        static map<pair<const Station*,const Station*>,int> sDistStations;
        
       
    private:
        //Constructor made private to prevent creation of objects
        Railways();

    public:
        ~Railways();
        
        // Singleton Railways
        static const Railways& IndianRailways()
        {
            static const Railways indianRailways;
            return indianRailways;
        }

    
        //Gets distance between two stations from their names
        const int GetDistance(const string& from,const string& to) const;

        // Gets Station from a given station name.
         const Station* GetStation(const string& stationName) const;
    

        void AddStation(const string& station);
        void AddDistance(const string& station1, const string& station2,int distance);

};

#endif
// End of "Railways.h"
