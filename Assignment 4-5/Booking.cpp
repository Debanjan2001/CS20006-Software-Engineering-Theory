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
#include "Railways.h"
#include "Exceptions.h"
#include "Date.h"

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

const int Booking::GetFare() const
{
    return fare_;
}

const Booking& Booking::CreateBooking(const string& from,const string& to,const Date& dateOfBooking,const Date& dateOfReservation, const BookingClasses& bookingClass, const BookingCategory& bookingCategory,const Passenger& passenger)
{
    const Station* fromStation = Railways::IndianRailways().GetStation(from);
    const Station* toStation = Railways::IndianRailways().GetStation(to);

    if( (fromStation == NULL) || (toStation ==NULL) )
        throw Bad_Booking("Bad_Booking: Either One or both of the Stations dont exist in master data");
    
    Date doReserve = dateOfReservation, doBook = dateOfBooking; 
    if ( (doReserve < doBook)==false )
        throw Bad_Booking("Bad_Booking: Date of Reservation does not precede Date of Booking");

    if(doBook.IsWithinAYear(doReserve) == false)
        throw Bad_Booking("Bad_Booking: Date of Booking is not within one year of Date of Reservation");

    Date dob = passenger.GetDateOfBirth();
    if( (dob < dateOfReservation)==false )
        throw Bad_Booking("Bad_Booking: Date of Birth of passenger does not precede Date of Reservation");

    if(bookingCategory.IsEligible(passenger,dateOfReservation,dateOfBooking) == false )
        throw Bad_Booking("Bad_Booking: Passenger is not eligible for the booking category");

    if(from == to)
        throw Bad_Booking("Bad_Booking: Destination and Source Station are same");

    Booking* b = new Booking(*fromStation,*toStation,dateOfBooking,dateOfReservation,bookingClass,bookingCategory,passenger);
    return *b;
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
    os<<"Reservation Date = "<<booking.dateOfReservation_<<"\n";
    os<<"Travel Date = "<<booking.dateOfBooking_<<"\n";
    os<<"Booking Class:"<<booking.bookingClass_.GetName()<<"\n";
    os<<"Booking Category:"<<booking.bookingCategory_.GetName()<<"\n";
    os<<"Fare = "<<booking.fare_<<"\n";
    os<<booking.passenger_<<endl;
    return os;
}

void Booking::UnitTestBooking()
{
    cout<<endl;

    int success = 0,totTest=0;

    cout<<"CHECKING FOR POSITIVE TESTS\n"<<endl;
    
    try
    {
        Passenger p = Passenger::CreatePassenger("Debanjan","","Saha",Gender::Male::Type(),"432768911196",Date::CreateDate(14,7,2001),"9830020322",&Disability::Blind::Type(),"22153");
        Booking b1 = Booking::CreateBooking("Kolkata","Delhi",Date::CreateDate(24,7,2021),Date::CreateDate(10,4,2021),BookingClasses::AC2Tier::Type(),General::Type(),p);
        if(b1.GetFare()!=2994)
            throw Bad_Booking("Bad_booking: Fare Generation method is not right.");
        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
        
    }
    catch(Bad_Booking& ex)
    {
        cout << ex.what() << '\n';
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;

    }

    try
    {
        Passenger p = Passenger::CreatePassenger("Debanjan","","Saha",Gender::Male::Type(),"432768911196",Date::CreateDate(14,7,1960),"9830020322");
        Booking::CreateBooking("Kolkata","Delhi",Date::CreateDate(24,7,2021),Date::CreateDate(10,4,2021),BookingClasses::AC2Tier::Type(),SeniorCitizen::Type(),p);
        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }
    catch(Bad_Booking& ex)
    {
        cout << ex.what() << '\n';
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;

    }

    cout<<endl;
    cout<<"CHECKING FOR NEGATIVE TESTS\n"<<endl;
    try
    {
        Passenger p = Passenger::CreatePassenger("Debanjan","","Saha",Gender::Male::Type(),"432768911196",Date::CreateDate(14,7,2001),"9830020322",&Disability::Blind::Type(),"22153");
        Booking::CreateBooking("Gujrat","Delhi",Date::CreateDate(24,7,2021),Date::CreateDate(10,4,2021),BookingClasses::AC2Tier::Type(),General::Type(),p);
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;
    }
    catch(Bad_Booking& ex)
    {
        cout<<ex.what()<<endl;
        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }

    try
    {
        Passenger p = Passenger::CreatePassenger("Debanjan","","Saha",Gender::Male::Type(),"432768911196",Date::CreateDate(14,7,2001),"9830020322",&Disability::Blind::Type(),"22153");
        Booking::CreateBooking("Kolkata","Delhi",Date::CreateDate(24,3,2021),Date::CreateDate(10,4,2021),BookingClasses::AC2Tier::Type(),General::Type(),p);
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;
    }
    catch(Bad_Booking& ex)
    {
        cout<<ex.what()<<endl;
        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }
    try
    {
        Passenger p = Passenger::CreatePassenger("Debanjan","","Saha",Gender::Male::Type(),"432768911196",Date::CreateDate(14,7,2001),"9830020322",&Disability::Blind::Type(),"22153");
        Booking::CreateBooking("Kolkata","Kolkata",Date::CreateDate(24,5,2021),Date::CreateDate(10,4,2021),BookingClasses::AC2Tier::Type(),General::Type(),p);
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;
    }
    catch(Bad_Booking& ex)
    {
        cout<<ex.what()<<endl;
        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }

    try
    {
        Passenger p = Passenger::CreatePassenger("Debanjan","","Saha",Gender::Male::Type(),"432768911196",Date::CreateDate(14,7,2001),"9830020322",&Disability::Blind::Type(),"22153");
        Booking::CreateBooking("Kolkata","Delhi",Date::CreateDate(24,8,2022),Date::CreateDate(10,4,2021),BookingClasses::AC2Tier::Type(),General::Type(),p);
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;
    }
    catch(Bad_Booking& ex)
    {
        cout<<ex.what()<<endl;
        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }

    try
    {
        Passenger p = Passenger::CreatePassenger("Debanjan","","Saha",Gender::Male::Type(),"432768911196",Date::CreateDate(14,8,2021),"9830020322",&Disability::Blind::Type(),"22153");
        Booking::CreateBooking("Kolkata","Delhi",Date::CreateDate(24,8,2021),Date::CreateDate(10,4,2021),BookingClasses::AC2Tier::Type(),General::Type(),p);
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;
    }
    catch(Bad_Booking& ex)
    {
        cout<<ex.what()<<endl;
        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }

    try
    {
        Passenger p = Passenger::CreatePassenger("Debjani","","",Gender::Female::Type(),"432768911196",Date::CreateDate(14,7,1963),"9830020322");
        Booking::CreateBooking("Kolkata","Delhi",Date::CreateDate(24,8,2021),Date::CreateDate(10,4,2021),BookingClasses::AC2Tier::Type(),SeniorCitizen::Type(),p);
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;
    }
    catch(Bad_Booking& ex)
    {
        cout<<ex.what()<<endl;
        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }

    try
    {
        Passenger p = Passenger::CreatePassenger("Debanjan","","Saha",Gender::Male::Type(),"432768911196",Date::CreateDate(14,8,1961),"9830020322");
        Booking::CreateBooking("Kolkata","Delhi",Date::CreateDate(24,8,2021),Date::CreateDate(10,4,2021),BookingClasses::AC2Tier::Type(),Divyaang::Type(),p);
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;
    }
    catch(Bad_Booking& ex)
    {
        cout<<ex.what()<<endl;
        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }

    cout<<endl;
    cout<<success<<" OUT OF "<<totTest<<" TESTS [PASSED]"<<endl;

}
