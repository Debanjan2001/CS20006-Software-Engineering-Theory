/*---------------- 
Debanjan Saha
19CS30014
-----------------*/
#ifndef _BOOKINGCLASSES_H
#define _BOOKINGCLASSES_H

#include<iostream>
#include<string>

using namespace std;

class BookingClasses
{
    protected:
        string name_;
        bool isSeat_,ac_,luxury_;
        int numTiers_;

    public:
        BookingClasses();
        string GetName() const;
        bool IsSitting() const;
        bool IsAC() const;
        int GetNumberOfTiers() const;
        bool IsLuxury() const;
        virtual ~BookingClasses();
};

class SeatingClass:public BookingClasses
{
    public:
        SeatingClass();
        virtual ~SeatingClass();

};

class BerthClass:public BookingClasses
{
    public:
        BerthClass();
        virtual ~BerthClass();        
};


class ACFirstClass:public BerthClass
{
    private:
        static const double sLoadFactor_;
    public:
        ACFirstClass();
        ~ACFirstClass();
        double GetLoadFactor() const;

        
};


class AC2Tier:public BerthClass
{
    private:
        static const double sLoadFactor_;


    public:
        AC2Tier();
        ~AC2Tier();
        double GetLoadFactor() const;

        
};


class FirstClass:public BerthClass
{
    private:
        static const double sLoadFactor_;


    public:
        FirstClass();
        ~FirstClass();
        double GetLoadFactor() const;

        
};


class AC3Tier:public BerthClass
{
    private:
        static const double sLoadFactor_;


    public:
        AC3Tier();
        ~AC3Tier();
        double GetLoadFactor() const;

        
};


class Sleeper:public BerthClass
{
    private:
        static const double sLoadFactor_;


    public:
        Sleeper();
        ~Sleeper();
        double GetLoadFactor() const;

        
};


class ACChairCar:public SeatingClass
{
    private:
        static const double sLoadFactor_;


    public:
        ACChairCar();
        ~ACChairCar();
        double GetLoadFactor() const;

        
};

class SecondSitting:public SeatingClass
{
    private:
        static const double sLoadFactor_;

    public:
        SecondSitting();
        ~SecondSitting();
        double GetLoadFactor() const;
        
};


#endif