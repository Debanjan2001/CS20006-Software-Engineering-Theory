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
        
        const int date_, month_, year_;

        //Constructor
        Date();
        Date(int d, int m, int y);
    
    public:

        // Destructor
        ~Date();

        const bool IsLeapYear() const;

        static const Date& CreateDate(int day,int month,int year);
        const int ComputeAge(const Date& otherDate) const;
       
        bool IsWithinAYear(const Date& dateOfBirth);
        bool operator==(const Date& date);

        // Output Stream Overloading friend function Declaration
        friend ostream& operator<<(ostream& os,const Date& date);
        
        bool operator<(const Date& date);
};

#endif
// End of "Date.h" 