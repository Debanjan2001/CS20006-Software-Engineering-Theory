/*---------------- 
Debanjan Saha
19CS30014
-----------------*/
// Start of "Date.h"
#ifndef _DATE_H
#define _DATE_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Date
{
    private:
        const static vector<string> sMonths;
        const static vector<string> sDays; 
        typedef unsigned int UINT;
        UINT day_; string month_; UINT year_;
    
    public:
        Date(UINT d, UINT m, UINT y);
        ~Date();

        friend ostream& operator<<(ostream& os,const Date& date)
        {
            os<< date.day_ <<"/"<< date.month_ <<"/"<<date.year_ ;
        }
};

#endif
// End of "Date.h" 