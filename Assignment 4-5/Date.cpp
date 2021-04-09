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
#include "Exceptions.h"

// Constructor with 3 parameters
Date::Date(int d, int m, int y): date_(d),month_(m),year_(y)
{}

// Destructor
Date::~Date()
{}

// Factory method for error handling before instantiation
const Date& Date::CreateDate(int date,int month,int year)
{
    vector<int> days ={31,28,31,30,31,30,31,31,30,31,30,31};
    if(IsLeapYear(year))
        days[1]++;

    if(year>2099 || year<1900)
        throw Bad_Date("Bad_Date: Invalid Year");

    if(month<1 || month>12)
        throw Bad_Date("Bad_Date: Invalid Month");

    if(date<1 || date>days[month-1])
        throw Bad_Date("Bad_Date: Invalid Date(Day number)");


    Date* newDate = new Date(date,month,year);
    return *newDate;
}

// check for leap year (helper function)
const bool Date::IsLeapYear(int year)
{
    if(year % 100 == 0)
        return !(year % 400);
    else
        return !(year % 4);
}

// Checks whether this date is within a year of otherdate
const bool Date::IsWithinAYear(const Date& otherDate) const 
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

// Checks whether this date precedes otherdate

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

    if(date_ < otherDate.date_ )
        return true;
    
    return false;
}

// age calculator
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

// equality operator overload
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

// unit test
void Date::UnitTestDate()
{
    cout<<endl;
    int success = 0,totTest=0;

    cout<<"CHECKING FOR POSITIVE TESTS\n"<<endl;
    
    try
    {
        Date d = Date::CreateDate(14,7,2001);
        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }
    catch(Bad_Date& ex)
    {
        cout << ex.what() << '\n';
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;

    }

    try
    {
        Date d = Date::CreateDate(14,7,2001);
        Date today = Date::CreateDate(9,4,2021);
        if(today.ComputeAge(d)!=19)
            throw Bad_Date("Bad_Date: Age Calculated is wrong");

        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }
    catch(Bad_Date& ex)
    {
        cout << ex.what() << '\n';
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;
    }

    try
    {
        Date d1 = Date::CreateDate(31,3,2021);
        Date d2 = Date::CreateDate(1,4,2021);
        if( (d1<d2) ==false )
            throw Bad_Date("Bad_Date: Overloaded operator is wrong");

        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }
    catch(Bad_Date& ex)
    {
        cout << ex.what() << '\n';
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;
    }

    try
    {
        Date d1 = Date::CreateDate(23,2,2021);
        Date d2 = Date::CreateDate(25,2,2021);
        if( (d1<d2) == false )
            throw Bad_Date("Bad_Date: Overloaded operator is wrong");

        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }
    catch(Bad_Date& ex)
    {
        cout << ex.what() << '\n';
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;
    }

    try
    {
        Date d1 = Date::CreateDate(23,2,2021);
        Date d2 = Date::CreateDate(23,2,2021);
        if( (d1==d2) ==false )
            throw Bad_Date("Bad_Date: Overloaded operator is wrong");

        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }
    catch(Bad_Date& ex)
    {
        cout << ex.what() << '\n';
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;
    }

    try
    {
        Date d = Date::CreateDate(29,2,2024);
        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }
    catch(Bad_Date& ex)
    {
        cout << ex.what() << '\n';
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;

    }

    try
    {
        Date d = Date::CreateDate(31,12,2099);
        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }
    catch(Bad_Date& ex)
    {
        cout << ex.what() << '\n';
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;

    }

    try
    {
        Date d1 = Date::CreateDate(25,7,2021);
        Date d2 = Date::CreateDate(24,8,2022);

        if(d2.IsWithinAYear(d1)==true)
            throw Bad_Date("Bad_Date: WithinAYear Function is erroneous");

        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }
    catch(Bad_Date& ex)
    {
        cout << ex.what() << '\n';
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;
    }
    cout<<endl;
    
    
    cout<<"CHECKING FOR NEGATIVE TESTS\n"<<endl;
    try
    {
        Date d = Date::CreateDate(14,7,1859);
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;
    }
    catch(Bad_Date& ex)
    {
        cout<<ex.what()<<endl;
        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }

    try
    {
        Date d = Date::CreateDate(14,7,2100);
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;
    }
    catch(Bad_Date& ex)
    {
        cout<<ex.what()<<endl;
        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }

    try
    {
        Date d = Date::CreateDate(31,4,2021);
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;
    }
    catch(Bad_Date& ex)
    {
        cout<<ex.what()<<endl;
        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }

    try
    {
        Date d = Date::CreateDate(29,2,2021);
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;
    }
    catch(Bad_Date& ex)
    {
        cout<<ex.what()<<endl;
        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }

    try
    {
        Date d = Date::CreateDate(32,3,2024);
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;
    }
    catch(Bad_Date& ex)
    {
        cout<<ex.what()<<endl;
        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }

    try
    {
        Date d = Date::CreateDate(0,3,2024);
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;
    }
    catch(Bad_Date& ex)
    {
        cout<<ex.what()<<endl;
        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }

    try
    {
        Date d = Date::CreateDate(12,0,2024);
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;
    }
    catch(Bad_Date& ex)
    {
        cout<<ex.what()<<endl;
        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }

    try
    {
        Date d = Date::CreateDate(12,13,2024);
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;
    }
    catch(Bad_Date& ex)
    {
        cout<<ex.what()<<endl;
        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }

    cout<<endl;
    cout<<success<<" OUT OF "<<totTest<<" TESTS [PASSED]"<<endl;

}





   
