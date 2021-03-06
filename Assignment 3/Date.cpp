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

//UnitTest
void Date::UnitTestDate()
{
    // Different cases of construction
    Date d1; // Default Date object with no parameter
    Date d2 = Date(14,7,2001); // Date with a user-defined date 

    if(d1.date_ != 1 || d1.sMonths[d1.month_-1] != "Jan" || d1.year_!= 1979)
        cout<<"  Date construction error on Date()"<<endl;
    else
        cout<<"  Subtest-1 Passed" <<endl;

    if(d2.date_ != 14 || d2.sMonths[d2.month_-1] != "Jul" || d2.year_!= 2001)
        cout<<"  Date construction error on Date(14,7,2001)"<<endl;
    else
        cout<<"  Subtest-2 Passed" <<endl;
}

// Friend function definition for output stream overloading
ostream& operator<<(ostream& os,const Date& date)
{
    os<< date.date_ <<"/"<< date.sMonths[date.month_-1] <<"/"<<date.year_ ;
    return os;
}



   
