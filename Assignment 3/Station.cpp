/*---------------- 
Debanjan Saha
19CS30014
-----------------*/

#include<iostream>
#include<string>
#include "Station.h"

using namespace std;

Station::Station(string name): name_(name)
{
}

string Station::GetName() const
{
    return name_;
}

// to be done
int Station::GetDistance() const
{
    return 0;
}

Station::~Station()
{}
