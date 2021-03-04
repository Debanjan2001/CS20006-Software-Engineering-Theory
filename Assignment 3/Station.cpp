/*---------------- 
Debanjan Saha
19CS30014
-----------------*/

#include<iostream>
#include<string>
using namespace std;

#include "Station.h"

Station::Station(string name): name_(name)
{}

string Station::GetName() const
{
    return name_;
}

int Station::GetDistance(Station& otherStation) const
{
    return (Railways::TheRailway()).GetDistance(name_,otherStation.GetName());
}

Station::~Station()
{}
