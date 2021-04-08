/*---------------- 
Debanjan Saha
19CS30014
-----------------*/

// ***** C++ Standard Library Headers
#include<iostream>
#include<string>
using namespace std;

// ***** Project Headers
#include "Passenger.h"

// Constructor
Passenger::Passenger(const string& fName,const string& mName,const string& lName,const string& aadhar,const Date& dob,const Gender& gender,const string& mobile,const Disability* disabilityType, const string& disabilityID ):
firstName_(fName),middleName_(mName),lastName_(lName),dateOfBirth_(dob),gender_(gender),aadhar_(aadhar),mobile_(mobile),disabilityID_(disabilityID),disabilityType_(disabilityType){};

Passenger Passenger::CreatePassenger(const Gender& gender,const string& aadhar,const Date& dob,const Disability* disabilityType,const string& mobile ="",const string& disabilityID = "",const string& fName = "",const string& mName = "",const string& lName = "" )
{
    return Passenger(fName,mName,lName,aadhar,dob,gender,mobile,disabilityType,disabilityID);
}

const Date& Passenger::GetDateOfBirth() const
{
    return dateOfBirth_;
}

const string Passenger::GetName() const
{
    return firstName_+ " "+ middleName_+ " "+lastName_;
}

const string Passenger::GetDisabilityID() const
{
    return disabilityID_;
}

const Gender& Passenger::GetGender() const
{
    return gender_;
}

const Disability* Passenger::GetDisabilityType() const
{
    return disabilityType_;
}

ostream& operator<<(ostream& os,const Passenger& passenger)
{
    os<< passenger.GetName()<<endl;
    return os;
}

//Destructor
Passenger::~Passenger()
{}

