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
Booking::Booking(const Station& from,const Station& to,const Date& date,const BookingClasses& bookingClass):
fromStation_(from),toStation_(to),date_(date),bookingClass_(bookingClass),pnrNumber_(sBookingPNRSerial++)
{
    //Initialised passenger as null.
    passenger_ = NULL;

    // Booking is successful always.
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
    os<<booking.bookingMessage_<<"\n";
    os<<"PNR NUMBER = "<<booking.pnrNumber_<<"\n";
    os<<"From Station = "<<booking.fromStation_.GetName()<<"\n";
    os<<"To Station = "<<booking.toStation_.GetName()<<"\n";
    os<<"Travel Date = "<<booking.date_<<"\n";
    os<<"Travel Class = "<<booking.bookingClass_.GetName()<<"\n";
    os<<" : Mode : "<< ((booking.bookingClass_.IsSitting())?"Sitting":"Sleeping" )<<"\n";
    os<<" : Comfort : "<< ((booking.bookingClass_.IsAC())?"AC":"Non-AC" ) <<"\n";
    os<<" : Bunks : "<< booking.bookingClass_.GetNumberOfTiers()<<"\n";
    os<<" : Luxury : "<< ((booking.bookingClass_.IsLuxury())?"Yes":"No")<<"\n";
    os<<"Fare = "<<booking.fare_<<"\n";
    return os;
}