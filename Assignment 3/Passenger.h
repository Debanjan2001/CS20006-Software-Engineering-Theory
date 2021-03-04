/*---------------- 
Debanjan Saha
19CS30014
-----------------*/
#ifndef _PASSENGER_H
#define _PASSENGER_H

#include<iostream>
#include<string>
using namespace std;

#include "Date.h"

class Date;

class Passenger
{
    private:
        string name_,gender_,category_;
        long long int aadhar_,mobile_;
        Date dateOfBirth_;

    public:
        Passenger(const string name,const long long int aadhar,const Date &dob,const string gender,const string category,const long long int mobile);        
        ~Passenger();

        // virtual string GetName() = 0;
};

#endif
