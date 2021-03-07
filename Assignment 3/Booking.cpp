/*---------------- 
Debanjan Saha
19CS30014
-----------------*/

// ***** C++ Standard Library Headers
#include<iostream>
#include<string>
#include<vector>
using namespace std;

// ***** Project Headers
#include "Booking.h"

// ***** Static Definitions
int Booking::sBookingPNRSerial = 1;
vector<Booking *> Booking::sBookings;

// ***** Static constant definitions.
const double Booking::sBaseFarePerKM = 0.50; 
const double Booking::sACSurcharge = 50.00; 
const double Booking::sLuxuryTaxPercent = 0.25; 

// Implementation of Booking class
Booking::Booking(const Station& from,const Station& to,const Date& date,const BookingClasses& bookingClass,const Passenger* passenger):
fromStation_(from),toStation_(to),date_(date),bookingClass_(bookingClass),pnrNumber_(sBookingPNRSerial++),passenger_(passenger)
{
    // Booking is always successful.
    bookingStatus_ = true;
    bookingMessage_ = "BOOKING SUCCEEDED";
    fare_ = ComputeFare();
    sBookings.push_back(this);
}

//Destructor
Booking::~Booking()
{}

//Gets Fare for a particular type of booking
int Booking::ComputeFare()
{
    double amount = 0.0;
    amount += sBaseFarePerKM * fromStation_.GetDistance(toStation_);
    amount = amount * bookingClass_.GetLoadFactor();

    if( bookingClass_.IsAC() )
        amount += sACSurcharge;

    if( bookingClass_.IsLuxury())
        amount += amount * sLuxuryTaxPercent;

    int finalAmount = static_cast<int>(amount+0.50);
    return finalAmount;
}

// Output Stream Overloading.
ostream& operator<<(ostream& os,const Booking& booking)
{
    os<<booking.bookingMessage_<<":\n";
    os<<"PNR Number = "<<booking.pnrNumber_<<"\n";
    os<<"From Station = "<<booking.fromStation_.GetName()<<"\n";
    os<<"To Station = "<<booking.toStation_.GetName()<<"\n";
    os<<"Travel Date = "<<booking.date_<<"\n";
    os<<booking.bookingClass_<<"\n";
    os<<"Fare = "<<booking.fare_<<"\n";
    return os;
}

void Booking::UnitTestBooking()
{
    Booking b1(Station("Kolkata"),Station("Chennai"),Date(14,7,2021),ACFirstClass::Type());

    if(b1.ComputeFare()!= 3173)
        cout<<"  Error on Booking(Station(\"Kolkata\"),Station(\"Chennai\"),Date(14,7,2021),ACFirstClass::Type()).ComputeFare()"<<endl;
    else
        cout<<"   Subtest-1 Passed"<<endl;
    
}