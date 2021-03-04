/*---------------- 
Debanjan Saha
19CS30014
-----------------*/
#ifndef __BOOKING_H
#define __BOOKING_H

#include<iostream>
#include<string>
#include<vector>
using namespace std;

#include "Station.h"
#include "Date.h"
#include "BookingClasses.h"
#include "Passenger.h"

class Station;
class Date;
class Passenger;

class Booking
{
    private:
        const Station fromStation_,toStation_ ;
        const Date date_;
        const BookingClasses& bookingClass_;
        const Passenger* passenger_;
        int fare_;
        const int pnrNumber_;
        bool bookingStatus_;
        string bookingMessage_; 

        static int sBookingPNRSerial;
        static const double sBaseFarePerKM, sACSurcharge, sLuxuryTaxPercent;
    
    public:
        static vector<Booking *> sBookings;

        Booking(const Station& from,const Station& to,const Date& date,const BookingClasses& bookingclass);
        ~Booking();
        virtual int ComputeFare();

        friend ostream& operator<<(ostream& os,const Booking& booking)
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

        
};

#endif
