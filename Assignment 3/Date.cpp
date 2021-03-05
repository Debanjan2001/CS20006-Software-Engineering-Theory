/*---------------- 
Debanjan Saha
19CS30014
-----------------*/
#include<iostream>
using namespace std;

#include "Date.h"

const vector<string> Date::sMonths = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Aug","Oct","Nov","Dec"};
const vector<string> Date::sDays = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

Date::Date():date_(1),month_(static_cast<Month>(1)),year_(1979)
{}

Date::Date(UINT d, UINT m, UINT y): date_(d),month_(static_cast<Month>(m)),year_(y)
{}

Date::~Date()
{}

ostream& operator<<(ostream& os,const Date& date)
{
    os<< date.date_ <<"/"<< date.sMonths[date.month_-1] <<"/"<<date.year_ ;
    return os;
}



   
