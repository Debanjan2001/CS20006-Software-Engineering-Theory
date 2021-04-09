/*---------------- 
Debanjan Saha
19CS30014
-----------------*/

// C++ Standard Headers
#include<iostream>
using namespace std;

// Project Headers

#include "Railways.h"
#include "Passenger.h"
#include "Booking.h"
#include "Station.h"
#include "Date.h"
#include "BookingClasses.h"
#include "BookingCategory.h"
#include "Disability.h"
#include "Gender.h"

int main()
{
    Passenger p1 = Passenger::CreatePassenger("Debanjan","","Saha",Gender::Male::Type(),"432715911196",Date::CreateDate(14,7,2001),"9800162288");
    Booking::CreateBooking("Delhi","Mumbai",Date::CreateDate(24,7,2021),Date::CreateDate(10,4,2021),BookingClasses::AC3Tier::Type(),General::Type(),p1);

    Booking::CreateBooking("Delhi","Mumbai",Date::CreateDate(28,7,2021),Date::CreateDate(10,4,2021),BookingClasses::ACFirstClass::Type(),General::Type(),p1); 

    Passenger p2 = Passenger::CreatePassenger("Arijit","","Ghosh",Gender::Male::Type(),"432768211196",Date::CreateDate(25,7,1960),"9830020322");
    Booking::CreateBooking("Delhi","Mumbai",Date::CreateDate(23,7,2021),Date::CreateDate(10,4,2021),BookingClasses::AC3Tier::Type(),SeniorCitizen::Type(),p2); 

    Passenger p3 = Passenger::CreatePassenger("Debjani","","Das",Gender::Female::Type(),"932768911196",Date::CreateDate(24,2,1962),"9094215647",&Disability::Blind::Type(),"22153");
    Booking::CreateBooking("Delhi","Mumbai",Date::CreateDate(24,7,2021),Date::CreateDate(10,4,2021),BookingClasses::ACFirstClass::Type(),SeniorCitizen::Type(),p3); 


    Passenger p4 = Passenger::CreatePassenger("Bob","","",Gender::Male::Type(),"125698742152",Date::CreateDate(20,5,1983),"8930015647",&Disability::Blind::Type(),"22153");
    Booking::CreateBooking("Delhi","Mumbai",Date::CreateDate(25,2,2022),Date::CreateDate(10,4,2021),BookingClasses::AC3Tier::Type(),Divyaang::Type(),p4); 

    Passenger p5 = Passenger::CreatePassenger("Harleen","","Kaur",Gender::Female::Type(),"654856327458",Date::CreateDate(20,3,1994),"6564487921",&Disability::Cancer::Type(),"22245");
    Booking::CreateBooking("Delhi","Mumbai",Date::CreateDate(24,7,2021),Date::CreateDate(10,4,2021),BookingClasses::ACFirstClass::Type(),Divyaang::Type(),p5); 
    
    Booking::CreateBooking("Delhi","Mumbai",Date::CreateDate(11,4,2021),Date::CreateDate(10,4,2021),BookingClasses::AC3Tier::Type(),Tatkal::Type(),p1); 

    Booking::CreateBooking("Chennai","Bangalore",Date::CreateDate(11,4,2021),Date::CreateDate(10,4,2021),BookingClasses::ACFirstClass::Type(),Tatkal::Type(),p2); 
    
    Passenger p6 = Passenger::CreatePassenger("Bhavna","Kumari","Rajakrishnan",Gender::Female::Type(),"432715923496",Date::CreateDate(14,7,1998),"9800162388");

    Booking::CreateBooking("Chennai","Bangalore",Date::CreateDate(24,7,2021),Date::CreateDate(10,4,2021),BookingClasses::AC3Tier::Type(),Ladies::Type(),p6); 

    Booking::CreateBooking("Chennai","Bangalore",Date::CreateDate(24,7,2021),Date::CreateDate(23,7,2021),BookingClasses::AC2Tier::Type(),PremiumTatkal::Type(),p6); 

    
    vector<Booking*>::iterator it;
    
    for (it = Booking::sBookings.begin(); it < Booking::sBookings.end(); ++it) {
        cout <<(*(*it))<<endl;
    }
    return 0;
}