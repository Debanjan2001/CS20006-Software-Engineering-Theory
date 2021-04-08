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
    const char* msg_;

    public:
        Bad_Date(const char*);
        const char* what() const throw();
};


class Bad_Passenger: public exception
{
    const char* msg_;

    public:
        Bad_Passenger(const char*);
        const char* what() const throw();
};

class Bad_Railways: public exception
{
    const char* msg_;

    public:
        Bad_Railways(const char*);
        const char* what() const throw();
};

class Bad_Booking: public exception
{
    const char* msg_;
    public:
        Bad_Booking(const char*);
        const char* what() const throw();
};

#endif