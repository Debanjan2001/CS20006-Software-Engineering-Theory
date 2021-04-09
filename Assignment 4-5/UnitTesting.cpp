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


int main()
{
    cout<<"********************************************************"<<endl;
    cout<<"Unit Test for Station: "<<endl;
    cout<<"********************************************************"<<endl;
    Station::UnitTestStation();
    cout<<endl;

    cout<<"********************************************************"<<endl;
    cout<<"Unit Test for Date: "<<endl;
    cout<<"********************************************************"<<endl;
    Date::UnitTestDate();
    cout<<endl;

    cout<<"********************************************************"<<endl;
    cout<<"Unit Test for Passenger: "<<endl;
    cout<<"********************************************************"<<endl;
    Passenger::UnitTestPassenger();
    cout<<endl;


    cout<<"********************************************************"<<endl;
    cout<<"Unit Test for Booking: "<<endl;
    cout<<"********************************************************"<<endl;
    Booking::UnitTestBooking();
    cout<<endl;

    return 0;
}