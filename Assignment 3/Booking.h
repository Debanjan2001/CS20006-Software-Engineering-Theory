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

        friend ostream& operator<<(ostream& os,const Booking& booking);

        
};

#endif
