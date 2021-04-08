/*---------------- 
Debanjan Saha
19CS30014
-----------------*/

// ***** C++ Standard Library Headers
#include<iostream>
using namespace std;

// ***** Project Headers
#include "Date.h"
#include "Exceptions.h"

//Forward Declaration
class Bad_Date;

// Constructor without parameters (Default set to 1/1/1979).Since 1979,C++ started being developed.
Date::Date():date_(1),month_(1),year_(1979)
{}

// Constructor with 3 parameters
Date::Date(int d, int m, int y): date_(d),month_(m),year_(y)
{}

// Destructor
Date::~Date()
{}

Date Date::CreateDate(int date,int month,int year)
{
    try
    {
    }
    catch(Bad_Date& err)
    {
        cerr << err.what();
    }

    return Date();
    
}

// bool Date::IsWithinAYear(const Date& otherDate)
// {   
// }

bool Date::operator==(const Date& date)
{
    return date_== date.date_ && month_ == date.month_ && year_ == date.year_;
}

// Friend function definition for output stream overloading
ostream& operator<<(ostream& os,const Date& date)
{
    os<< date.date_ <<"/"<< date.month_ <<"/"<<date.year_ ;
    return os;
}

//UnitTest
void Date::UnitTestDate()
{
   
}




   
