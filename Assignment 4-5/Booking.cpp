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
#include "Exceptions.h"

// ***** Static Definitions
int Booking::sBookingPNRSerial = 1;
vector<Booking *> Booking::sBookings;

// Implementation of Booking class
Booking::Booking(const Station& fromStation,const Station& toStation,const Date& dateOfBooking, const Date& dateOfReservation, const BookingClasses& bookingClass, const BookingCategory& bookingCategory,const Passenger& passenger):
fromStation_(fromStation),toStation_(toStation),dateOfBooking_(dateOfBooking),dateOfReservation_(dateOfReservation),bookingClass_(bookingClass),bookingCategory_(bookingCategory),pnrNumber_(sBookingPNRSerial++),passenger_(passenger)
{
    // Booking is always successful.
    bookingStatus_ = true;
    bookingMessage_ = "BOOKING SUCCEEDED";
    int distance = Railways::IndianRailways().GetDistance(fromStation.GetName(),toStation.GetName());
    fare_ = bookingCategory_.CalculateFare(passenger_,bookingClass_,distance);
    sBookings.push_back(this);
}

const Booking& Booking::CreateBooking(const Station& fromStation,const Station& toStation,const Date& dateOfBooking, const Date& dateOfReservation, const BookingClasses& bookingClass, const BookingCategory& bookingCategory,const Passenger& passenger)
{
    try
    {
        if(false)
        {
            throw Bad_Booking("Bad");
        }
        else
        {
            Booking* b = new Booking(fromStation,toStation,dateOfBooking,dateOfReservation,bookingClass,bookingCategory,passenger);
            return *b;
        }
    }
    catch(const Bad_Booking& e)
    {
        cout<< e.what() << '\n';
        throw e;
    }
}

//Destructor
Booking::~Booking()
{}


// Output Stream Overloading.
ostream& operator<<(ostream& os,const Booking& booking)
{
    os<<booking.bookingMessage_<<":\n";
    os<<"PNR Number = "<<booking.pnrNumber_<<"\n";
    os<<"From Station = "<<booking.fromStation_.GetName()<<"\n";
    os<<"To Station = "<<booking.toStation_.GetName()<<"\n";
    os<<"Travel Date = "<<booking.dateOfReservation_<<"\n";
    os<<booking.bookingClass_.GetName()<<"\n";
    os<<"Fare = "<<booking.fare_<<"\n";
    os<<"Passenger is: "<<booking.passenger_<<endl;
    return os;
}
