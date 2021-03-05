/*---------------- 
Debanjan Saha
19CS30014
-----------------*/
// Start of "Date.h"
#ifndef __DATE_H
#define __DATE_H

// ***** C++ Standard Library Headers
#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Date in format dd/mmm/yyyy 
class Date
{
    private:
        // List of months and days
        const static vector<string> sMonths;
        const static vector<string> sDays;

        // enum of Month and Day
        enum Month { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
        enum Day { Mon, Tue, Wed, Thr, Fri, Sat, Sun };
        
        typedef unsigned int UINT;
        UINT date_; Month month_; UINT year_;
    
    public:

        // Constructor and Destructor
        Date();
        Date(UINT d, UINT m, UINT y);
        ~Date();

        // Output Stream Overloading friend function Declaration
        friend ostream& operator<<(ostream& os,const Date& date);
};

#endif
// End of "Date.h" 