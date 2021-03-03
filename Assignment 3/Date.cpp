/*---------------- 
Debanjan Saha
19CS30014
-----------------*/
#include<iostream>
using namespace std;

#include "Date.h"

const vector<string> Date::sMonths = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Aug","Oct","Nov","Dec"};
const vector<string> Date::sDays = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

Date::Date(UINT d, UINT m, UINT y): day_(d),year_(y)
{
    month_ = sMonths[m-1];
}

Date::~Date()
{}



   
