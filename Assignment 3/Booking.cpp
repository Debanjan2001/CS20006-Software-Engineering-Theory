/*---------------- 
Debanjan Saha
19CS30014
-----------------*/
#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

#include "Booking.h"

int Booking::sBookingPNRSerial = 1;
vector<Booking *> Booking::sBookings;

const double Booking::sBaseFarePerKM = 0.50; 
const double Booking::sACSurcharge = 50.00; 
const double Booking::sLuxuryTaxPercent = 0.25; 

Booking::Booking(const Station& from,const Station& to,const Date& date,const BookingClasses& bookingClass):
fromStation_(from),toStation_(to),date_(date),bookingClass_(bookingClass),pnrNumber_(sBookingPNRSerial++)
{
    passenger_ = NULL;
    bookingStatus_ = true;
    bookingMessage_ = "BOOKING SUCCEEDED";
    fare_ = ComputeFare();
    sBookings.push_back(this);
}

Booking::~Booking()
{}

int Booking::ComputeFare()
{
    double amount = 0.0;
    amount += sBaseFarePerKM * fromStation_.GetDistance(toStation_);
    amount = amount * bookingClass_.GetLoadFactor();

    if( bookingClass_.IsAC() )
        amount += sACSurcharge;

    if( bookingClass_.IsLuxury())
        amount += amount * sLuxuryTaxPercent;

    int finalAmount = round(amount);
    return finalAmount;
}

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