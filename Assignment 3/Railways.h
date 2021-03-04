/*---------------- 
Debanjan Saha
19CS30014
-----------------*/
#ifndef _RAILWAYS_H
#define _RAILWAYS_H

#include<iostream>
#include<string>
#include<map>
using namespace std;

#include "Station.h"

// class Station;

class Railways
{
    private:
        static map<const string,const Station*> sStations;
        static map<pair<const Station*,const Station*>,int> sDistStations;

    public:
        Railways();
        ~Railways();
        
        static const Railways& TheRailway()
        {
            static const Railways IndianRailways;
            return IndianRailways;
        }

        
        int GetDistance(string from,string to) const;

};

#endif
