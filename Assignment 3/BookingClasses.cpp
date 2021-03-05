/*---------------- 
Debanjan Saha
19CS30014
-----------------*/
#include<iostream>
#include<string>

using namespace std;

#include "BookingClasses.h"


BookingClasses::BookingClasses(string name,bool isSeat,bool ac,bool luxury,int numTiers):
name_(name),isSeat_(isSeat),ac_(ac),luxury_(luxury),numTiers_(numTiers)
{}

string BookingClasses::GetName() const
{
    return name_;
}

bool BookingClasses::IsSitting() const
{
    return isSeat_;
}

bool BookingClasses::IsAC() const
{
    return ac_;
}

int BookingClasses::GetNumberOfTiers() const
{
    return numTiers_;
}

bool BookingClasses::IsLuxury() const 
{
    return luxury_;
}

BookingClasses::~BookingClasses(){}

SeatingClass::SeatingClass(string name,bool ac,bool luxury,int numTiers):BookingClasses(name,true,ac,luxury,numTiers)
{}

SeatingClass::~SeatingClass(){}

BerthClass::BerthClass(string name,bool ac,bool luxury,int numTiers):BookingClasses(name,false,ac,luxury,numTiers)
{}

BerthClass::~BerthClass(){}

ACFirstClass::ACFirstClass():BerthClass("AC First Class",true,true,2)
{}

ACFirstClass::~ACFirstClass(){}

double ACFirstClass::GetLoadFactor() const
{
    return sLoadFactor;
}


AC2Tier::AC2Tier():BerthClass("AC 2 Tier",true,false,2)
{}

AC2Tier::~AC2Tier(){}

double AC2Tier::GetLoadFactor() const
{
    return sLoadFactor;
}


FirstClass::FirstClass():BerthClass("First Class",false,true,2)
{}

FirstClass::~FirstClass(){}

double FirstClass::GetLoadFactor() const
{
    return sLoadFactor;
}

AC3Tier::AC3Tier():BerthClass("AC 3 Tier",true,false,3)
{}

AC3Tier::~AC3Tier(){}

double AC3Tier::GetLoadFactor() const
{
    return sLoadFactor;
}


ACChairCar::ACChairCar():SeatingClass("AC Chair Car",true,false,0)
{}

ACChairCar::~ACChairCar(){}

double ACChairCar::GetLoadFactor() const
{
    return sLoadFactor;
}


Sleeper::Sleeper():BerthClass("Sleeper",false,false,3)
{}

Sleeper::~Sleeper(){}


double Sleeper::GetLoadFactor() const
{
    return sLoadFactor;
}

SecondSitting::SecondSitting():SeatingClass("Second Sitting",false,false,0)
{}

SecondSitting::~SecondSitting(){}


double SecondSitting::GetLoadFactor() const
{
    return sLoadFactor;
}



const double ACFirstClass::sLoadFactor = 3.00;
const double AC2Tier::sLoadFactor = 2.00;
const double FirstClass::sLoadFactor = 2.00;
const double AC3Tier::sLoadFactor = 1.75;
const double ACChairCar::sLoadFactor = 1.25;
const double Sleeper::sLoadFactor = 1.00;
const double SecondSitting::sLoadFactor = 0.50;

