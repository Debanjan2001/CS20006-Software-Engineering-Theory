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
        static const ACFirstClass& Type()
        {
            static const ACFirstClass obj;
            return obj;
        }
        double GetLoadFactor() const;

        
};


class AC2Tier:public BerthClass
{
    private:
        static const double sLoadFactor_;


    public:
        AC2Tier();
        ~AC2Tier();
        static const AC2Tier& Type()
        {
            static const AC2Tier obj;
            return obj;
        }
        double GetLoadFactor() const;

        
};


class FirstClass:public BerthClass
{
    private:
        static const double sLoadFactor_;


    public:
        FirstClass();
        ~FirstClass();
        static const FirstClass& Type()
        {
            static const FirstClass obj;
            return obj;
        }
        double GetLoadFactor() const;

        
};


class AC3Tier:public BerthClass
{
    private:
        static const double sLoadFactor_;


    public:
        AC3Tier();
        ~AC3Tier();
        static const AC3Tier& Type()
        {
            static const AC3Tier obj;
            return obj;
        }
        double GetLoadFactor() const;

        
};


class Sleeper:public BerthClass
{
    private:
        static const double sLoadFactor_;


    public:
        Sleeper();
        ~Sleeper();
        static const Sleeper& Type()
        {
            static const Sleeper obj;
            return obj;
        }
        double GetLoadFactor() const;
};


class ACChairCar:public SeatingClass
{
    private:
        static const double sLoadFactor_;


    public:
        ACChairCar();
        ~ACChairCar();
        static const ACChairCar& Type()
        {
            static const ACChairCar obj;
            return obj;
        }
        double GetLoadFactor() const;

        
};

class SecondSitting:public SeatingClass
{
    private:
        static const double sLoadFactor_;

    public:
        SecondSitting();
        ~SecondSitting();
        static const SecondSitting& Type()
        {
            static const SecondSitting obj;
            return obj;
        }
        double GetLoadFactor() const;
        
};


#endif