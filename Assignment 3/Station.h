/*---------------- 
Debanjan Saha
19CS30014
-----------------*/
#ifndef __STATION_H
#define __STATION_H

#include<iostream>
#include<string>
using namespace std;

#include "Railways.h"

class Railways;

class Station
{
    private:
        string name_;
    
    public: 
        Station();
        Station(string name);
        string GetName() const;
        int GetDistance (const Station& otherStation) const;
        ~Station();

};

#endif