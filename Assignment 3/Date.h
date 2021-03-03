/*---------------- 
Debanjan Saha
19CS30014
-----------------*/
// Start of "Date.h"
#ifndef _DATE_H
#define _DATE_H
#include<iostream>
#include<string>
using namespace std;

class Date
{
    private:
        enum sMonths { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
        typedef unsigned int UINT;
        UINT day_; sMonths month_; UINT year_;
    
    public:
        Date(UINT d, UINT m, UINT y);
        ~Date();
};

#endif
// End of "Date.h" 