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
#include "BookingCategory.h"

// Forward declarations
class Station;
class Date;
class Passenger;

class Booking
{
    private:
        
        //constant data members
        const Station& fromStation_,toStation_ ;
        const Date& dateOfBooking_,dateOfReservation_;
        const BookingClasses& bookingClass_;
        const BookingCategory& bookingCategory_;
        const Passenger& passenger_;
        const int pnrNumber_;

        // Booking status and message.
        string bookingMessage_; 
        bool bookingStatus_;

        // To be calculated from ComputeFare Method
        int fare_;

        //Constants for a booking- PNR no.,Base fare, AC charge, Luxury Charge 
        static int sBookingPNRSerial;

        //Constructor and Destructor
        Booking(const Station& fromStation,const Station& toStation,const Date& dateOfBooking, const Date& dateOfReservation, const BookingClasses& bookingClass, const BookingCategory& bookingCategory,const Passenger& passenger);

    public:
        // List of all bookings done
        ~Booking();

        // static list of all bookings
        static vector<Booking *> sBookings;

        // Factory Method for error handling before instatntiation
        static const Booking& CreateBooking(const string& from,const string& to,const Date& dateOfBooking,const Date& dateOfReservation, const BookingClasses& bookingClass, const BookingCategory& bookingCategory,const Passenger& passenger);

        // Gets fare for all types of booking
        const int GetFare() const;

        // Output Stream overloading 
        friend ostream& operator<<(ostream& os,const Booking& booking);

        // Static method for unit testing 
        static void UnitTestBooking();

           
};

#endif
// End of "Booking.h"
