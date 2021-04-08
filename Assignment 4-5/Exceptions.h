/*---------------- 
Debanjan Saha
19CS30014
-----------------*/
#ifndef __EXCEPTIONS_H
#define __EXCEPTIONS_H

#include<iostream>
using namespace std;

class Bad_Date: public exception
{
    public:
        const char* what() const throw();
};


class Bad_Passenger: public exception
{
    public:
        const char* what() const throw();
};

class Bad_Railways: public exception
{
    public:
        const char* what() const throw();
};

class Bad_Booking: public exception
{
    public:
        const char* what() const throw();
};

#endif