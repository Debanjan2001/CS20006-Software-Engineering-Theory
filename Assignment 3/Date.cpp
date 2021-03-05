/*---------------- 
Debanjan Saha
19CS30014
-----------------*/

// ***** C++ Standard Library Headers
#include<iostream>
using namespace std;

// ***** Project Headers
#include "Date.h"

// ***** Static definitions
const vector<string> Date::sMonths = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Aug","Oct","Nov","Dec"};
const vector<string> Date::sDays = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

// Constructor without parameters (Default set to 1/1/1979).Since 1979,C++ started being developed.
Date::Date():date_(1),month_(static_cast<Month>(1)),year_(1979)
{}

// Constructor with 3 parameters
Date::Date(UINT d, UINT m, UINT y): date_(d),month_(static_cast<Month>(m)),year_(y)
{}

// Destructor
Date::~Date()
{}

// Friend function definition for output stream overloading
ostream& operator<<(ostream& os,const Date& date)
{
    os<< date.date_ <<"/"<< date.sMonths[date.month_-1] <<"/"<<date.year_ ;
    return os;
}



   
