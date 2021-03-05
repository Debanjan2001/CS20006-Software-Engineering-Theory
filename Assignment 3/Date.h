/*---------------- 
Debanjan Saha
19CS30014
-----------------*/
// Start of "Date.h"
#ifndef __DATE_H
#define __DATE_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Date
{
    private:
        const static vector<string> sMonths;
        const static vector<string> sDays; 
        enum Month { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
        enum Day { Mon, Tue, Wed, Thr, Fri, Sat, Sun };
        
        typedef unsigned int UINT;
        UINT date_; Month month_; UINT year_;
    
    public:
        Date();
        Date(UINT d, UINT m, UINT y);
        ~Date();

        friend ostream& operator<<(ostream& os,const Date& date);
};

#endif
// End of "Date.h" 