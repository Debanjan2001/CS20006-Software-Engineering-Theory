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

        //Private Constructor for factory function call
        Passenger(const string& fName,const string& mName,const string& lName,const string& aadhar,const Date& dob,const Gender& gender,const string& mobile,const Disability* disabilityType, const string& disabilityID );        


    public:
        //Constructor and Destructor
        ~Passenger();

        // Factory method for error handling and creation of instances
        static const Passenger& CreatePassenger(const string& fName ,const string& mName ,const string& lName , const Gender& gender,const string& aadhar,const Date& dob,const string& mobile ="",const Disability* disabilityType = NULL,const string& disabilityID ="");

        //Getter methods
        const string GetName() const;
        const Disability* GetDisabilityType() const;
        const Gender& GetGender() const;
        const Date& GetDateOfBirth() const;
        const string GetDisabilityID() const;

        //Output stream overloaded
        friend ostream& operator<<(ostream& os,const Passenger& passenger);

        //Static method for unit-testing
        static void UnitTestPassenger();
};  

#endif
// End of "Passenger.h"
