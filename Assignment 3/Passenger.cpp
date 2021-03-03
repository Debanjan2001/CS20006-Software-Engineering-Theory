/*---------------- 
Debanjan Saha
19CS30014
-----------------*/

#include<iostream>
#include<string>
using namespace std;

#include "Passenger.h"


Passenger::Passenger(string name,long long int aadhar,Date &dob,string gender,string category,long long int mobile = 0):
name_(name),aadhar_(aadhar),dateOfBirth_(dob),gender_(gender),category_(category),mobile_(mobile)
{
}

Passenger::~Passenger()
{}

