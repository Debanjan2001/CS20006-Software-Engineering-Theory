/*---------------- 
Debanjan Saha
19CS30014
-----------------*/

#include<iostream>
#include<string>
using namespace std;

#include "Passenger.h"


Passenger::Passenger(const string name,const long long int aadhar,const Date &dob,const string gender,const string category,const long long int mobile):
name_(name),dateOfBirth_(dob),gender_(gender),category_(category)
{
    aadhar_ = static_cast<long long int>(aadhar);
    mobile_ =static_cast<long long int>(mobile);
}

Passenger::Passenger():name_(""),aadhar_(0),dateOfBirth_(Date(1,1,1979)),gender_(""),category_(""),mobile_(0)
{}

Passenger::~Passenger()
{}

