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

// Date in format dd/mm/yyyy 
class Date
{
    private:
        
        const int date_, month_, year_;

        //Private Constructor
        Date(int d, int m, int y);
        static const bool IsLeapYear(int year);

    public:
        // Destructor
        ~Date();

        //Factory method for Creation of Date with error handling
        static const Date& CreateDate(int day,int month,int year);

        // Helper methods
        const int ComputeAge(const Date& otherDate) const;
        const bool IsWithinAYear(const Date& dateOfBirth) const;
        
        bool operator<(const Date& date);
        bool operator==(const Date& date);

        // Output Stream Overloading friend function Declaration
        friend ostream& operator<<(ostream& os,const Date& date);
        

        //static method for unit tests
        static void UnitTestDate();
};

#endif
// End of "Date.h" 