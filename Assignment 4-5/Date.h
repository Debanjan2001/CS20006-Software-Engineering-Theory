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

        static Date CreateDate(int day,int month,int year);
        int ComputeAge(const Date& otherDate);
        bool IsWithinAYear(const Date& otherDate);
        bool operator==(const Date& date);

        // Output Stream Overloading friend function Declaration
        friend ostream& operator<<(ostream& os,const Date& date);
        
        bool operator<(const Date& date);
        //Static method to test class Date
        static void UnitTestDate();
};

#endif
// End of "Date.h" 