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
        if(false)
        {
            throw Bad_Date("Error");
        }
        else
        {
            return Date(date,month,year);
        }
    }
    catch(Bad_Date& err)
    {
        throw err;
    }
}

const bool Date::IsLeapYear() const
{
    if(year_ % 100 == 0)
        return !(year_ % 400);
    else
        return !(year_ % 4);
}

bool Date::IsWithinAYear(const Date& otherDate)
{
    if(year_-otherDate.year_>1)
        return false;
    if(year_==otherDate.year_)
        return true;
    
    if(month_> otherDate.month_)
        return false;

    if(month_ == otherDate.month_ && date_ >otherDate.date_ )
        return false;
    else
        return true;

}

bool Date::operator<(const Date& otherDate)
{
    if(year_>otherDate.year_)
        return false;
    
    if(year_<otherDate.year_)
        return true;

    if(month_ > otherDate.month_ )
        return false;

    if(month_ < otherDate.month_ )
        return true;

    if(date_ > otherDate.date_)
        return false;

    if(month_ < otherDate.month_ )
        return true;
    
    return false;
}

const int Date::ComputeAge(const Date& dateOfBirth) const
{
    int age = year_ - dateOfBirth.year_;

    if(month_ < dateOfBirth.month_)
    {
        age--;
        return age;
    }

    if(month_ == dateOfBirth.month_ && date_<dateOfBirth.date_) 
    {
        age--;
        return age;
    }

    return age;
}


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





   
