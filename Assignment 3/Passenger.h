/*---------------- 
Debanjan Saha
19CS30014
-----------------*/
#ifndef _PASSENGER_H
#define _PASSENGER_H

#include<iostream>
#include<string>

#include "Date.h"

using namespace std;

class Passenger
{
    private:
        string name_,gender_,category_;
        long long int aadhar_,mobile_;
        Date dateOfBirth_;

    public:
        Passenger(string name,long long int aadhar,Date &dob,string gender,string category,long long int mobile);        
        ~Passenger();
};

#endif