/*---------------- 
Debanjan Saha
19CS30014
-----------------*/

#include<iostream>
using namespace std;

#include "Exceptions.h"

const char* Bad_Date::what() const throw()
{
    return "Exception occured.Error in date";
}

const char* Bad_Station::what() const throw()
{
    return "Exception occured.Error in station";
}

const char* Bad_Railways::what() const throw()
{
    return "Exception occured.Error in Railways";
}

const char* Bad_Booking::what() const throw()
{
    return "Exception occured.Error in Booking";
}