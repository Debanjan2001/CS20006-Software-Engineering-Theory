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

int main()
{
    cout<<"TESTING class Date"<<endl;
    Date::UnitTestDate();
    cout<<endl;

    cout<<"TESTING class Station"<<endl;
    Station::UnitTestStation();
    cout<<endl;

    cout<<"TESTING class ACFirstClass"<<endl;
    ACFirstClass::UnitTestACFirstClass();
    cout<<endl;

    cout<<"TESTING class AC2Tier"<<endl;
    AC2Tier::UnitTestAC2Tier();
    cout<<endl;

    cout<<"TESTING class FirstClass"<<endl;
    FirstClass::UnitTestFirstClass();
    cout<<endl;

    cout<<"TESTING class AC3Tier"<<endl;
    AC3Tier::UnitTestAC3Tier();
    cout<<endl;

    cout<<"TESTING class ACChairCar"<<endl;
    ACChairCar::UnitTestACChairCar();
    cout<<endl;

    cout<<"TESTING class Sleeper"<<endl;
    Sleeper::UnitTestSleeper();
    cout<<endl;

    cout<<"TESTING class SecondSitting"<<endl;
    SecondSitting::UnitTestSecondSitting();
    cout<<endl;

    cout<<"TESTING class Booking"<<endl;
    Booking::UnitTestBooking();
    cout<<endl;


}