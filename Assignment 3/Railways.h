/*---------------- 
Debanjan Saha
19CS30014
-----------------*/
#ifndef _RAILWAYS_H
#define _RAILWAYS_H

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include "Station.h"

using namespace std;

class Railways
{
    private:
        // static vector<Station> sStations;
        static map<const string,const Station*> sStations;
        static map<pair<const Station*,const Station*>,int> sDistStations;

    public:
        static const Railways& TheRailway()
        {
            static const Railways IndianRailways;
            return IndianRailways;
        }

        Railways();
        ~Railways();
        int GetDistance(string from,string to);

};

#endif
