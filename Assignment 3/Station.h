/*---------------- 
Debanjan Saha
19CS30014
-----------------*/
#ifndef _STATION_H
#define _STATION_H

#include<iostream>
#include<string>

using namespace std;

class Station
{
    private:
        string name_;
    
    public: 
        Station(string name);
        string GetName() const;
        int GetDistance () const;
        ~Station();

};

#endif