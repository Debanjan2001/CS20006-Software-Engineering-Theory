/*---------------- 
Debanjan Saha
19CS30014
-----------------*/

// Start of "Station.h"

#ifndef __STATION_H
#define __STATION_H

// ***** C++ Standard Library Headers
#include<iostream>
#include<string>
using namespace std;

// ***** Project Headers
#include "Railways.h"

// Forward declaration
class Railways;

class Station
{
    private:
        string name_;
    
    public: 
        //Constructor and Destructor
        Station();
        Station(const string name);
        ~Station();

        //Gets name of Station
        string GetName() const;

        //Gets distance from self to another Station.
        int GetDistance (const Station& otherStation) const;

        // Output Stream Overloading
        friend ostream& operator<<(ostream& os,const Station& station);
};

#endif
// End of "Station.h"