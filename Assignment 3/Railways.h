/*---------------- 
Debanjan Saha
19CS30014
-----------------*/
#ifndef __RAILWAYS_H
#define __RAILWAYS_H

#include<iostream>
#include<string>
#include<map>
using namespace std;

#include "Station.h"

class Station;

class Railways
{
    private:
        static map<const string,const Station*> sStations;
        static map<pair<const Station*,const Station*>,int> sDistStations;
        
        const Station* GetStation(const string& stationName) const;
    
    public:
        Railways();
        ~Railways();
        
        static const Railways& IndianRailways()
        {
            static const Railways indianRailways;
            return indianRailways;
        }

        int GetDistance(const string& from,const string& to) const;
        
};

#endif
