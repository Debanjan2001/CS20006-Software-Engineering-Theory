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
    return sLoadFactor_;
}


AC2Tier::AC2Tier():BerthClass("AC 2 Tier",true,false,2)
{}

AC2Tier::~AC2Tier(){}

double AC2Tier::GetLoadFactor() const
{
    return sLoadFactor_;
}


FirstClass::FirstClass():BerthClass("First Class",false,true,2)
{}

FirstClass::~FirstClass(){}

double FirstClass::GetLoadFactor() const
{
    return sLoadFactor_;
}

AC3Tier::AC3Tier():BerthClass("AC 3 Tier",true,false,3)
{}

AC3Tier::~AC3Tier(){}

double AC3Tier::GetLoadFactor() const
{
    return sLoadFactor_;
}


ACChairCar::ACChairCar():SeatingClass("AC Chair Car",true,false,0)
{}

ACChairCar::~ACChairCar(){}

double ACChairCar::GetLoadFactor() const
{
    return sLoadFactor_;
}


Sleeper::Sleeper():BerthClass("Sleeper",false,false,3)
{}

Sleeper::~Sleeper(){}


double Sleeper::GetLoadFactor() const
{
    return sLoadFactor_;
}

SecondSitting::SecondSitting():SeatingClass("Second Sitting",false,false,0)
{}

SecondSitting::~SecondSitting(){}


double SecondSitting::GetLoadFactor() const
{
    return sLoadFactor_;
}



const double ACFirstClass::sLoadFactor_ = 3.00;
const double AC2Tier::sLoadFactor_ = 2.00;
const double FirstClass::sLoadFactor_ = 2.00;
const double AC3Tier::sLoadFactor_ = 1.75;
const double ACChairCar::sLoadFactor_ = 1.25;
const double Sleeper::sLoadFactor_ = 1.00;
const double SecondSitting::sLoadFactor_ = 0.50;

