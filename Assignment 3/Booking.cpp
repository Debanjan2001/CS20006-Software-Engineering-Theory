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
vector<Booking *> Booking::sBookings = vector<Booking *>();
const double Booking::sBaseFarePerKM = 0.50; 
const double Booking::sACSurcharge = 50.00; 
const double Booking::sLuxuryTaxPercent = 0.25; 


Booking::Booking(Station& from,Station& to,Date& date,const BookingClasses& bookingClass):
fromStation_(from),toStation_(to),date_(date),bookingClass_(bookingClass)
{
    pnrNumber_ = sBookingPNRSerial++;
    bookingStatus_ = true;
    bookingMessage_ = "BOOKING SUCCEEDED";
    this->ComputeFare();
    sBookings.push_back(this);
}

Booking::~Booking()
{
    delete passenger_;
}

void Booking::ComputeFare()
{
    double amount = 0.0;
    amount += sBaseFarePerKM * fromStation_.GetDistance(toStation_);
    amount = amount * bookingClass_.GetLoadFactor();
    if( bookingClass_.IsAC())
        amount += sACSurcharge;

    if( bookingClass_.IsLuxury())
        amount = amount + amount * sLuxuryTaxPercent;

    fare_ = round(amount);
}

