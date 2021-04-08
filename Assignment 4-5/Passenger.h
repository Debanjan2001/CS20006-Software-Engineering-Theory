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
#include "Disability.h"
#include "Gender.h"

// Abstract Base Class Passenger
class Passenger
{
    private:
        const string firstName_,lastName_,middleName_, aadhar_,mobile_;
        const Disability* disabilityType_;
        const Gender& gender_;
        const Date& dateOfBirth_;
        const string disabilityID_;

        Passenger(const string fName,const string mName,const string lName,const string aadhar,const Date& dob,const Gender& gender,const string mobile,const Disability* disabilityType, const string disabilityID );        


    public:
        //Constructor and Destructor
        ~Passenger();

        static Passenger CreatePassenger(const Gender& gender,const string aadhar,const Date& dob,const Disability* disabilityType,const string mobile ,const string disabilityID ,const string fName ,const string mName ,const string lName  );

        const string GetName() const;
        const Disability* GetDisabilityType() const;
        const Gender& GetGender() const;
        const Date& GetDateOfBirth() const;
        const string GetDisabilityID() const;

        friend ostream& operator<<(ostream& os,const Passenger& passenger);
};  

#endif
// End of "Passenger.h"
