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
Passenger::Passenger(const string name,const long long int aadhar,const Date &dob,const string gender,const string category,const long long int mobile):
name_(name),dateOfBirth_(dob),gender_(gender),category_(category)
{
    //Assigns data members with appropriate values 
    aadhar_ = static_cast<long long int>(aadhar);
    mobile_ =static_cast<long long int>(mobile);
}

// Default Constructor
Passenger::Passenger():name_(""),aadhar_(0),dateOfBirth_(Date()),gender_(""),category_(""),mobile_(0)
{}

//Destructor
Passenger::~Passenger()
{}

