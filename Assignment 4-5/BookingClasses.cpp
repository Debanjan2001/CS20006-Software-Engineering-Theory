/*---------------- 
Debanjan Saha
19CS30014
-----------------*/

// ***** C++ Standard Library Headers
#include<iostream>
#include<string>
using namespace std;

// ***** Project Headers
#include "BookingClasses.h"

// Implementation of BookingClasses
BookingClasses::BookingClasses(const string name,const bool isSeat,const bool ac,bool luxury,const int numTiers):
name_(name),isSeat_(isSeat),ac_(ac),luxury_(luxury),numTiers_(numTiers)
{}

// Gets name of bookingclass
string BookingClasses::GetName() const
{
    return name_;
}

bool BookingClasses::IsSitting() const
{
    // Returns true if it has seats only and not berth.
    return isSeat_;
}

bool BookingClasses::IsAC() const
{
    // returns true if it has AC
    return ac_;
}

int BookingClasses::GetNumberOfTiers() const
{
    // return number of Tiers of its booking class
    return numTiers_;
}

bool BookingClasses::IsLuxury() const 
{
    // returns true if it is a luxury booking class
    return luxury_;
}

BookingClasses::~BookingClasses(){}

// Implementation of SeatingClass
SeatingClass::SeatingClass(const string name,const bool ac,bool luxury,const int numTiers):BookingClasses(name,true,ac,luxury,numTiers)
{}

SeatingClass::~SeatingClass(){}

// Implementation of BerthClass
BerthClass::BerthClass(const string name,const bool ac,bool luxury,const int numTiers):BookingClasses(name,false,ac,luxury,numTiers)
{}

BerthClass::~BerthClass(){}

// Implementation of ACFirstClass
ACFirstClass::ACFirstClass():BerthClass("AC First Class",true,true,2)
{}

ACFirstClass::~ACFirstClass(){}

double ACFirstClass::GetLoadFactor() const
{
    //returns Load factor of this class
    return sLoadFactor;
}

//Implementation of AC2Tier
AC2Tier::AC2Tier():BerthClass("AC 2 Tier",true,false,2)
{}

AC2Tier::~AC2Tier(){}

double AC2Tier::GetLoadFactor() const
{
    //returns Load factor of this class
    return sLoadFactor;
}

//Implementation of FirstClass
FirstClass::FirstClass():BerthClass("First Class",false,true,2)
{}

FirstClass::~FirstClass(){}

double FirstClass::GetLoadFactor() const
{
    //returns Load factor of this class
    return sLoadFactor;
}

//Implementation of AC3Tier
AC3Tier::AC3Tier():BerthClass("AC 3 Tier",true,false,3)
{}

AC3Tier::~AC3Tier(){}

double AC3Tier::GetLoadFactor() const
{
    //returns Load factor of this class
    return sLoadFactor;
}

// AC Chair Car Implementation
ACChairCar::ACChairCar():SeatingClass("AC Chair Car",true,false,0)
{}

ACChairCar::~ACChairCar(){}

double ACChairCar::GetLoadFactor() const
{
    //returns Load factor of this class
    return sLoadFactor;
}

//Implementation of Sleeper
Sleeper::Sleeper():BerthClass("Sleeper",false,false,3)
{}

Sleeper::~Sleeper(){}


double Sleeper::GetLoadFactor() const
{
    //returns Load factor of this class
    return sLoadFactor;
}

//Implementation of SecondSitting
SecondSitting::SecondSitting():SeatingClass("Second Sitting",false,false,0)
{}

SecondSitting::~SecondSitting(){}


double SecondSitting::GetLoadFactor() const
{
    //returns Load factor of this class
    return sLoadFactor;
}

//Static Constant definitions 
const double ACFirstClass::sLoadFactor = 3.00;
const double AC2Tier::sLoadFactor = 2.00;
const double FirstClass::sLoadFactor = 2.00;
const double AC3Tier::sLoadFactor = 1.75;
const double ACChairCar::sLoadFactor = 1.25;
const double Sleeper::sLoadFactor = 1.00;
const double SecondSitting::sLoadFactor = 0.50;

//Output Stream Overload Implementation

ostream& operator<<(ostream& os,const BookingClasses& bookingClass)
{
    os<<"Travel Class = "<<bookingClass.GetName()<<"\n";
    os<<"  : Mode: "<< ((bookingClass.IsSitting())?"Sitting":"Sleeping" )<<"\n";
    os<<"  : Comfort: "<< ((bookingClass.IsAC())?"AC":"Non-AC" ) <<"\n";
    os<<"  : Bunks: "<< bookingClass.GetNumberOfTiers()<<"\n";
    os<<"  : Luxury: "<< ((bookingClass.IsLuxury())?"Yes":"No");
    return os;
}

ostream& operator<<(ostream& os, const ACFirstClass& acFirstClass )
{
    os<<"Travel Class = "<<acFirstClass.GetName()<<"\n";
    os<<"  : Mode: "<< ((acFirstClass.IsSitting())?"Sitting":"Sleeping" )<<"\n";
    os<<"  : Comfort: "<< ((acFirstClass.IsAC())?"AC":"Non-AC" ) <<"\n";
    os<<"  : Bunks: "<< acFirstClass.GetNumberOfTiers()<<"\n";
    os<<"  : Luxury: "<< ((acFirstClass.IsLuxury())?"Yes":"No")<<"\n";
    return os;
}

ostream& operator<<(ostream& os, const FirstClass& firstClass )
{
    os<<"Travel Class = "<<firstClass.GetName()<<"\n";
    os<<"  : Mode: "<< ((firstClass.IsSitting())?"Sitting":"Sleeping" )<<"\n";
    os<<"  : Comfort: "<< ((firstClass.IsAC())?"AC":"Non-AC" ) <<"\n";
    os<<"  : Bunks: "<< firstClass.GetNumberOfTiers()<<"\n";
    os<<"  : Luxury: "<< ((firstClass.IsLuxury())?"Yes":"No")<<"\n";
    return os;
}


ostream& operator<<(ostream& os, const AC2Tier& ac2Tier )
{
    os<<"Travel Class = "<<ac2Tier.GetName()<<"\n";
    os<<"  : Mode: "<< ((ac2Tier.IsSitting())?"Sitting":"Sleeping" )<<"\n";
    os<<"  : Comfort: "<< ((ac2Tier.IsAC())?"AC":"Non-AC" ) <<"\n";
    os<<"  : Bunks: "<< ac2Tier.GetNumberOfTiers()<<"\n";
    os<<"  : Luxury: "<< ((ac2Tier.IsLuxury())?"Yes":"No")<<"\n";
    return os;
}


ostream& operator<<(ostream& os, const AC3Tier& ac3Tier )
{
    os<<"Travel Class = "<<ac3Tier.GetName()<<"\n";
    os<<"  : Mode: "<< ((ac3Tier.IsSitting())?"Sitting":"Sleeping" )<<"\n";
    os<<"  : Comfort: "<< ((ac3Tier.IsAC())?"AC":"Non-AC" ) <<"\n";
    os<<"  : Bunks: "<< ac3Tier.GetNumberOfTiers()<<"\n";
    os<<"  : Luxury: "<< ((ac3Tier.IsLuxury())?"Yes":"No")<<"\n";
    return os;
}

ostream& operator<<(ostream& os, const Sleeper& sleeper )
{
    os<<"Travel Class = "<<sleeper.GetName()<<"\n";
    os<<"  : Mode: "<< ((sleeper.IsSitting())?"Sitting":"Sleeping" )<<"\n";
    os<<"  : Comfort: "<< ((sleeper.IsAC())?"AC":"Non-AC" ) <<"\n";
    os<<"  : Bunks: "<< sleeper.GetNumberOfTiers()<<"\n";
    os<<"  : Luxury: "<< ((sleeper.IsLuxury())?"Yes":"No")<<"\n";
    return os;
}

ostream& operator<<(ostream& os, const ACChairCar& acChairCar )
{
    os<<"Travel Class = "<<acChairCar.GetName()<<"\n";
    os<<"  : Mode: "<< ((acChairCar.IsSitting())?"Sitting":"Sleeping" )<<"\n";
    os<<"  : Comfort: "<< ((acChairCar.IsAC())?"AC":"Non-AC" ) <<"\n";
    os<<"  : Bunks: "<< acChairCar.GetNumberOfTiers()<<"\n";
    os<<"  : Luxury: "<< ((acChairCar.IsLuxury())?"Yes":"No")<<"\n";
    return os;
}

ostream& operator<<(ostream& os, const SecondSitting& secondSitting )
{
    os<<"Travel Class = "<<secondSitting.GetName()<<"\n";
    os<<"  : Mode: "<< ((secondSitting.IsSitting())?"Sitting":"Sleeping" )<<"\n";
    os<<"  : Comfort: "<< ((secondSitting.IsAC())?"AC":"Non-AC" ) <<"\n";
    os<<"  : Bunks: "<< secondSitting.GetNumberOfTiers()<<"\n";
    os<<"  : Luxury: "<< ((secondSitting.IsLuxury())?"Yes":"No")<<"\n";
    return os;
}

// Unit Tests Implementations

void ACFirstClass::UnitTestACFirstClass()
{
    // Singleton Object
    const ACFirstClass& acFirstClass = ACFirstClass::Type();

    if( acFirstClass.GetName()!= "AC First Class")
        cout<<"  Error on ACFirstClass::Type().GetName()"<<endl;
    else
        cout<<"  Subtest-1 Passed"<<endl;

    if( acFirstClass.IsSitting()!= false)
        cout<<"  Error on ACFirstClass::Type().IsSitting()"<<endl;
    else
        cout<<"  Subtest-2 Passed"<<endl;

    if( acFirstClass.IsLuxury() != true)
        cout<<"  Error on ACFirstClass::Type().IsLuxury"<<endl;
    else
        cout<<"  Subtest-3 Passed"<<endl;

    if( acFirstClass.IsAC()!= true)
        cout<<"  Error on ACFirstClass::Type().IsAC()"<<endl;
    else
        cout<<"  Subtest-4 Passed"<<endl;

    if( acFirstClass.GetNumberOfTiers()!= 2)
        cout<<"  Error on ACFirstClass::Type().GetNumberOfTiers()"<<endl;
    else
        cout<<"  Subtest-5 Passed"<<endl;

    if( acFirstClass.GetLoadFactor()!= 3.00)
        cout<<"  Error on ACFirstClass::Type().GetLoadFactor()"<<endl;
    else
        cout<<"  Subtest-6 Passed"<<endl;
}


void AC2Tier::UnitTestAC2Tier()
{
    // Singleton Object
    const AC2Tier& ac2Tier = AC2Tier::Type();

    if( ac2Tier.GetName()!= "AC 2 Tier")
        cout<<"  Error on AC2Tier::Type().GetName()"<<endl;
    else
        cout<<"  Subtest-1 Passed"<<endl;

    if( ac2Tier.IsSitting()!= false)
        cout<<"  Error on AC2Tier::Type().IsSitting()"<<endl;
    else
        cout<<"  Subtest-2 Passed"<<endl;

    if( ac2Tier.IsLuxury() != false)
        cout<<"  Error on AC2Tier::Type().IsLuxury"<<endl;
    else
        cout<<"  Subtest-3 Passed"<<endl;

    if( ac2Tier.IsAC()!= true)
        cout<<"  Error on AC2Tier::Type().IsAC()"<<endl;
    else
        cout<<"  Subtest-4 Passed"<<endl;

    if( ac2Tier.GetNumberOfTiers()!= 2)
        cout<<"  Error on AC2Tier::Type().GetNumberOfTiers()"<<endl;
    else
        cout<<"  Subtest-5 Passed"<<endl;

    if( ac2Tier.GetLoadFactor()!= 2.00)
        cout<<"  Error on AC2Tier::Type().GetLoadFactor()"<<endl;
    else
        cout<<"  Subtest-6 Passed"<<endl;
}


void FirstClass::UnitTestFirstClass()
{
    // Singleton Object
    const FirstClass& firstClass = FirstClass::Type();

    if( firstClass.GetName()!= "First Class")
        cout<<"  Error on FirstClass::Type().GetName()"<<endl;
    else
        cout<<"  Subtest-1 Passed"<<endl;

    if( firstClass.IsSitting()!= false)
        cout<<"  Error on FirstClass::Type().IsSitting()"<<endl;
    else
        cout<<"  Subtest-2 Passed"<<endl;

    if( firstClass.IsLuxury() != true)
        cout<<"  Error on FirstClass::Type().IsLuxury"<<endl;
    else
        cout<<"  Subtest-3 Passed"<<endl;

    if( firstClass.IsAC()!= false)
        cout<<"  Error on FirstClass::Type().IsAC()"<<endl;
    else
        cout<<"  Subtest-4 Passed"<<endl;

    if( firstClass.GetNumberOfTiers()!= 2)
        cout<<"  Error on FirstClass::Type().GetNumberOfTiers()"<<endl;
    else
        cout<<"  Subtest-5 Passed"<<endl;

    if( firstClass.GetLoadFactor() != 2.00)
        cout<<"  Error on FirstClass::Type().GetLoadFactor()"<<endl;
    else
        cout<<"  Subtest-6 Passed"<<endl;
}

void AC3Tier::UnitTestAC3Tier()
{
    // Singleton Object
    const AC3Tier& ac3Tier = AC3Tier::Type();

    if( ac3Tier.GetName()!= "AC 3 Tier")
        cout<<"  Error on AC3Tier::Type().GetName()"<<endl;
    else
        cout<<"  Subtest-1 Passed"<<endl;

    if( ac3Tier.IsSitting()!= false)
        cout<<"  Error on AC3Tier::Type().IsSitting()"<<endl;
    else
        cout<<"  Subtest-2 Passed"<<endl;

    if( ac3Tier.IsLuxury() != false)
        cout<<"  Error on AC3Tier::Type().IsLuxury"<<endl;
    else
        cout<<"  Subtest-3 Passed"<<endl;

    if( ac3Tier.IsAC()!= true)
        cout<<"  Error on AC3Tier::Type().IsAC()"<<endl;
    else
        cout<<"  Subtest-4 Passed"<<endl;

    if( ac3Tier.GetNumberOfTiers()!= 3)
        cout<<"  Error on AC3Tier::Type().GetNumberOfTiers()"<<endl;
    else
        cout<<"  Subtest-5 Passed"<<endl;

    if( ac3Tier.GetLoadFactor()!= 1.75)
        cout<<"  Error on AC3Tier::Type().GetLoadFactor()"<<endl;
    else
        cout<<"  Subtest-6 Passed"<<endl;
}


void ACChairCar::UnitTestACChairCar()
{
    // Singleton Object
    const ACChairCar& acChairCar = ACChairCar::Type();

    if( acChairCar.GetName()!= "AC Chair Car")
        cout<<"  Error on ACFirstClass::Type().GetName()"<<endl;
    else
        cout<<"  Subtest-1 Passed"<<endl;

    if( acChairCar.IsSitting()!= true)
        cout<<"  Error on ACChairCar::Type().IsSitting()"<<endl;
    else
        cout<<"  Subtest-2 Passed"<<endl;

    if( acChairCar.IsLuxury() != false)
        cout<<"  Error on ACChairCar::Type().IsLuxury"<<endl;
    else
        cout<<"  Subtest-3 Passed"<<endl;

    if( acChairCar.IsAC()!= true)
        cout<<"  Error on ACChairCar::Type().IsAC()"<<endl;
    else
        cout<<"  Subtest-4 Passed"<<endl;

    if( acChairCar.GetNumberOfTiers()!= 0)
        cout<<"  Error on ACChairCar::Type().GetNumberOfTiers()"<<endl;
    else
        cout<<"  Subtest-5 Passed"<<endl;

    if( acChairCar.GetLoadFactor()!= 1.25)
        cout<<"  Error on ACChairCar::Type().GetLoadFactor()"<<endl;
    else
        cout<<"  Subtest-6 Passed"<<endl;
}


void Sleeper::UnitTestSleeper()
{
    // Singleton Object
    const Sleeper& sleeper = Sleeper::Type();

    if( sleeper.GetName()!= "Sleeper")
        cout<<"  Error on Sleeper::Type().GetName()"<<endl;
    else
        cout<<"  Subtest-1 Passed"<<endl;

    if( sleeper.IsSitting()!= false)
        cout<<"  Error on Sleeper::Type().IsSitting()"<<endl;
    else
        cout<<"  Subtest-2 Passed"<<endl;

    if( sleeper.IsLuxury() != false)
        cout<<"  Error on Sleeper::Type().IsLuxury"<<endl;
    else
        cout<<"  Subtest-3 Passed"<<endl;

    if( sleeper.IsAC()!= false)
        cout<<"  Error on Sleeper::Type().IsAC()"<<endl;
    else
        cout<<"  Subtest-4 Passed"<<endl;

    if( sleeper.GetNumberOfTiers()!= 3)
        cout<<"  Error on Sleeper::Type().GetNumberOfTiers()"<<endl;
    else
        cout<<"  Subtest-5 Passed"<<endl;

    if( sleeper.GetLoadFactor()!= 1.00)
        cout<<"  Error on Sleeper::Type().GetLoadFactor()"<<endl;
    else
        cout<<"  Subtest-6 Passed"<<endl;
}


void SecondSitting::UnitTestSecondSitting()
{
    // Singleton Object
    const SecondSitting& secondSitting = SecondSitting::Type();

    if( secondSitting.GetName()!= "Second Sitting")
        cout<<"  Error on SecondSitting::Type().GetName()"<<endl;
    else
        cout<<"  Subtest-1 Passed"<<endl;

    if( secondSitting.IsSitting()!=true)
        cout<<"  Error on SecondSitting::Type().IsSitting()"<<endl;
    else
        cout<<"  Subtest-2 Passed"<<endl;

    if( secondSitting.IsLuxury() != false)
        cout<<"  Error on SecondSitting::Type().IsLuxury"<<endl;
    else
        cout<<"  Subtest-3 Passed"<<endl;

    if( secondSitting.IsAC()!= false)
        cout<<"  Error on SecondSitting::Type().IsAC()"<<endl;
    else
        cout<<"  Subtest-4 Passed"<<endl;

    if( secondSitting.GetNumberOfTiers()!= 0)
        cout<<"  Error on SecondSitting::Type().GetNumberOfTiers()"<<endl;
    else
        cout<<"  Subtest-5 Passed"<<endl;

    if( secondSitting.GetLoadFactor()!= 0.50)
        cout<<"  Error on SecondSitting::Type().GetLoadFactor()"<<endl;
    else
        cout<<"  Subtest-6 Passed"<<endl;
}