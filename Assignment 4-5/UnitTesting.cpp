#include<iostream>
using namespace std;

#include "Railways.h"
#include "Passenger.h"
#include "Booking.h"
#include "Station.h"
#include "Date.h"


int main()
{
    cout<<"***************************"<<endl;
    cout<<"Unit Test for Station: "<<endl;
    cout<<"***************************"<<endl;
    Station::UnitTestStation();
    cout<<endl;

    cout<<"***************************"<<endl;
    cout<<"Unit Test for Date: "<<endl;
    cout<<"***************************"<<endl;
    Date::UnitTestDate();
    cout<<endl;

    cout<<"***************************"<<endl;
    cout<<"Unit Test for Passenger: "<<endl;
    cout<<"***************************"<<endl;
    Passenger::UnitTestPassenger();
    cout<<endl;

    return 0;
}