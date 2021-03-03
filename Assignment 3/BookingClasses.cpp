/*---------------- 
Debanjan Saha
19CS30014
-----------------*/
#include<iostream>
#include<string>
using namespace std;

#include "BookingClasses.h"


BookingClasses::BookingClasses(){}

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

SeatingClass::SeatingClass()
{
    isSeat_ = true;
}

SeatingClass::~SeatingClass(){}

BerthClass::BerthClass()
{
    isSeat_ = false;
}

BerthClass::~BerthClass(){}

ACFirstClass::ACFirstClass()
{
    name_ = "AC First Class";
    ac_ = true;
    numTiers_ = 2;
    luxury_ = true;
}

ACFirstClass::~ACFirstClass(){}

double ACFirstClass::GetLoadFactor() const
{
    return sLoadFactor_;
}


AC2Tier::AC2Tier()
{
    name_ = "AC 2 Tier";
    ac_ = true;
    numTiers_ = 2;
    luxury_ = false;
}

AC2Tier::~AC2Tier(){}

double AC2Tier::GetLoadFactor() const
{
    return sLoadFactor_;
}


FirstClass::FirstClass()
{
    name_ = "First Class";
    ac_ = false;
    numTiers_ = 2;
    luxury_ = true;
}

FirstClass::~FirstClass(){}

double FirstClass::GetLoadFactor() const
{
    return sLoadFactor_;
}

AC3Tier::AC3Tier()
{
    name_ = "AC 3 Tier";
    ac_ = true;
    numTiers_ = 3;
    luxury_ = false;
}

AC3Tier::~AC3Tier(){}

double AC3Tier::GetLoadFactor() const
{
    return sLoadFactor_;
}



ACChairCar::ACChairCar()
{
    name_ = "AC Chair Car";
    ac_ = true;
    numTiers_ = 0;
    luxury_ = false;
}

ACChairCar::~ACChairCar(){}


double ACChairCar::GetLoadFactor() const
{
    return sLoadFactor_;
}


Sleeper::Sleeper()
{
    name_ = "Sleeper";
    ac_ = false;
    numTiers_ = 3;
    luxury_ = false;
}

Sleeper::~Sleeper(){}


double Sleeper::GetLoadFactor() const
{
    return sLoadFactor_;
}

SecondSitting::SecondSitting()
{
    name_ = "Second Sitting";
    ac_ = false;
    numTiers_ = 0;
    luxury_ = false;
}

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

