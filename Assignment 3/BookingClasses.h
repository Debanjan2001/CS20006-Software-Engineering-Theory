/*---------------- 
Debanjan Saha
19CS30014
-----------------*/
#ifndef __BOOKINGCLASSES_H
#define __BOOKINGCLASSES_H

// ***** C++ Standard Library Headers
#include<iostream>
#include<string>
using namespace std;

class BookingClasses
{
    protected:
        const string name_;
        const bool isSeat_,ac_;
        const int numTiers_;

        //Not constant since it is changeable according to tax rules
        bool luxury_;


    public:
        BookingClasses(const string name,const bool isSeat,const bool ac,bool luxury,const int numTiers);
        string GetName() const;
        bool IsSitting() const;
        bool IsAC() const;
        int GetNumberOfTiers() const;
        bool IsLuxury() const;
        virtual double GetLoadFactor() const = 0;
        virtual ~BookingClasses() = 0;
};

class SeatingClass:public BookingClasses
{
    public:
        SeatingClass(const string name,const bool ac,bool luxury,const int numTiers);
        virtual double GetLoadFactor() const = 0;
        virtual ~SeatingClass();

};

class BerthClass:public BookingClasses
{
    public:
        BerthClass(const string name,const bool ac,bool luxury,const int numTiers);
        virtual double GetLoadFactor() const = 0;
        virtual ~BerthClass();        
};


class ACFirstClass:public BerthClass
{
    private:
        static const double sLoadFactor;
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
        static const double sLoadFactor;


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
        static const double sLoadFactor;


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
        static const double sLoadFactor;


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
        static const double sLoadFactor;


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
        static const double sLoadFactor;


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
        static const double sLoadFactor;

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