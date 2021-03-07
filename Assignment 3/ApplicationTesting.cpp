/*---------------- 
Debanjan Saha
19CS30014
-----------------*/

// ***** C++ Standard Library Headers

#include<iostream>
#include<vector>
using namespace std;

// ***** Project Headers
#include "Date.h"
#include "Station.h"
#include "BookingClasses.h"
#include "Booking.h"


// Test application 1 for booking.
void BookingApplicationTest1()
{
    Booking b1(Station("Kolkata"), Station("Chennai"), Date(14,7,2021), ACFirstClass::Type());
    Booking b2(Station("Chennai"), Station("Bangalore"), Date(15,7,2021), AC2Tier::Type());
    Booking b3(Station("Bangalore"), Station("Delhi"), Date(16,7,2021), FirstClass::Type());
    Booking b4(Station("Delhi"), Station("Mumbai"), Date(17,7,2021), ACChairCar::Type());
    Booking b5(Station("Mumbai"), Station("Kolkata"), Date(18,7,2021), AC3Tier::Type());
   
    // Output the bookings done where sBookings is the collection of bookings done
    vector<Booking*>::iterator it;
    for (it = Booking::sBookings.begin(); it < Booking::sBookings.end(); ++it) {
        cout << *(*it)<<endl;
    }
}

// Test application 2 for booking.
void BookingApplicationTest2()
{
    Booking b1(Station("Mumbai"), Station("Delhi"), Date(15, 2, 2021), ACFirstClass::Type());
    Booking b2(Station("Kolkata"), Station("Delhi"), Date(5, 3, 2021), AC2Tier::Type());
    Booking b3(Station("Mumbai"), Station("Kolkata"), Date(17, 3, 2021), FirstClass::Type());
    Booking b4(Station("Mumbai"), Station("Delhi"), Date(23, 3, 2021), AC3Tier::Type());
    Booking b5(Station("Chennai"), Station("Delhi"), Date(25, 4, 2021), ACChairCar::Type());
    Booking b6(Station("Chennai"), Station("Kolkata"), Date(7, 5, 2021), Sleeper::Type());
    Booking b7(Station("Mumbai"), Station("Delhi"), Date(19, 5, 2021), SecondSitting::Type());
    Booking b8(Station("Delhi"), Station("Mumbai"), Date(22, 5, 2021), SecondSitting::Type());

    // Output the bookings done where sBookings is the collection of bookings done
    vector<Booking*>::iterator it;
    for (it = Booking::sBookings.begin(); it < Booking::sBookings.end(); ++it) {
        cout << *(*it)<<endl;
    }
}

int main()
{
    cout<<"OUTPUT FOR TEST-1"<<endl;
    BookingApplicationTest1();
    cout<<endl;

    cout<<"OUTPUT FOR TEST-2 (from Slides)"<<endl;
    BookingApplicationTest2();
    cout<<endl;
}