/*---------------- 
Debanjan Saha
19CS30014
-----------------*/
// ***** C++ Standard Library Headers
#include<iostream>
using namespace std;

//Project Headers
#include "Exceptions.h"

// Constructor(Initialiser with message) ******************** 
Bad_Booking::Bad_Booking(const char* message):msg_(message){};

Bad_Date::Bad_Date(const char* message):msg_(message){};

Bad_Railways::Bad_Railways(const char* message):msg_(message){};

Bad_Passenger::Bad_Passenger(const char* message):msg_(message){};
//*********************************************************************

//***********Thrown message 
const char* Bad_Date::what() const throw()
{
    return msg_;
}

const char* Bad_Passenger::what() const throw()
{
    return msg_;
}

const char* Bad_Railways::what() const throw()
{
    return msg_;
}

const char* Bad_Booking::what() const throw()
{
    return msg_;
}
//**************************************