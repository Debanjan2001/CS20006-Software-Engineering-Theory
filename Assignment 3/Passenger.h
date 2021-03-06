/*---------------- 
Debanjan Saha
19CS30014
-----------------*/

// Start of "Passenegr.h"
#ifndef __PASSENGER_H
#define __PASSENGER_H

// ***** C++ Standard Library Headers
#include<iostream>
#include<string>
using namespace std;

// ***** Project Headers
#include "Date.h"

// Forward declaration
class Date;

// Abstract Base Class Passenger
class Passenger
{
    private:
        const string name_,gender_,category_;
        const long long int aadhar_,mobile_;
        const Date dateOfBirth_;

    public:
        //Constructor and Destructor
        Passenger();
        Passenger(const string name,const long long int aadhar,const Date &dob,const string gender,const string category,const long long int mobile);        
        ~Passenger();

        // pure virtual getter method of passenger 
        // I made it pure to make it abstract base class.
        // virtual string GetName() = 0;
};

#endif
// End of "Passenger.h"
