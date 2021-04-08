/*---------------- 
Debanjan Saha
19CS30014
-----------------*/

// Start of "Booking.h"

#ifndef __BOOKING_H
#define __BOOKING_H

// ***** C++ Standard Library Headers
#include<iostream>
#include<string>
#include<vector>
using namespace std;

// ***** Project Headers
#include "Station.h"
#include "Date.h"
#include "BookingClasses.h"
#include "Passenger.h"

// Forward declarations
class Station;
class Date;
class Passenger;

class Booking
{
    private:
        const Station& fromStation_,toStation_ ;
        const Date& date_;
        const BookingClasses& bookingClass_;
        const Passenger* passenger_;
        const int pnrNumber_;

        // Booking status and message.
        string bookingMessage_; 
        bool bookingStatus_;


        // To be calculated from ComputeFare Method
        int fare_;

        //Constants for a booking- PNR no.,Base fare, AC charge, Luxury Charge 
        static int sBookingPNRSerial;
        static const double sBaseFarePerKM, sACSurcharge, sLuxuryTaxPercent;

    public:

        // List of all bookings done
        static vector<Booking *> sBookings;

        //Constructor and Destructor
        Booking(const Station& from,const Station& to,const Date& date,const BookingClasses& bookingclass,const Passenger* passenger = NULL);
        ~Booking();

        // Gets fare for all types of booking
        virtual int ComputeFare();

        // Output Stream overloading 
        friend ostream& operator<<(ostream& os,const Booking& booking);

        //Static method to test class Booking
        static void UnitTestBooking();
        
};

#endif
// End of "Booking.h"
