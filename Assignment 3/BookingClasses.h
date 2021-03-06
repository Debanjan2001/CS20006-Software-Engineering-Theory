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

//Abstract base class BookingClasses
class BookingClasses
{
    private:
        const string name_;
        const bool isSeat_,ac_;
        const int numTiers_;

        //Not constant since it is changeable according to tax rules
        bool luxury_;

    protected:
        //Kept protected to prevent Instance Creation
        BookingClasses(const string name,const bool isSeat,const bool ac,bool luxury,const int numTiers);
        virtual ~BookingClasses() = 0;

    public:
        string GetName() const;
        bool IsSitting() const;
        bool IsAC() const;
        int GetNumberOfTiers() const;
        bool IsLuxury() const;
        virtual double GetLoadFactor() const = 0;

        //Output stream overloading for printing in Booking Class
        friend ostream& operator<<(ostream& os,const BookingClasses& bookingClass);
};

//Base Class SeatingClass
class SeatingClass:public BookingClasses
{
    // Protected to prevent creating objects 
    protected:
        SeatingClass(const string name,const bool ac,bool luxury,const int numTiers);
        ~SeatingClass();

};

//Base Class BerthClass
class BerthClass:public BookingClasses
{
    // Protected to prevent creating objects 
    protected:
        BerthClass(const string name,const bool ac,bool luxury,const int numTiers);
        ~BerthClass();        
};

class ACFirstClass:public BerthClass
{
    private:
        static const double sLoadFactor;
         ACFirstClass();
        ~ACFirstClass();

    public:

        //Singleton ACFirstClass
        static const ACFirstClass& Type()
        {
            static const ACFirstClass obj;
            return obj;
        }
        double GetLoadFactor() const;

        //Output Stream Overloading
        friend ostream& operator<<(ostream& os,const ACFirstClass& acFirstClass);


        //Static method to test clTestACFirstClass
        static void UnitTestACFirstClass();
        
};


class AC2Tier:public BerthClass
{
    private:
        static const double sLoadFactor;

        //Private Constructor
        AC2Tier();
        ~AC2Tier();

    public:

        //Singleton AC2Tier
        static const AC2Tier& Type()
        {
            static const AC2Tier obj;
            return obj;
        }
        double GetLoadFactor() const;

        //Output Stream Overloading
        friend ostream& operator<<(ostream& os,const AC2Tier& ac2Tier);


        //Static method to test classtAC2Tier
        static void UnitTestAC2Tier();

        
};


class FirstClass:public BerthClass
{
    private:
        static const double sLoadFactor;
        FirstClass();
        ~FirstClass();

    public:
        

        //Singleton FirstClass
        static const FirstClass& Type()
        {
            static const FirstClass obj;
            return obj;
        }
        double GetLoadFactor() const;

        //Output Stream Overloading
        friend ostream& operator<<(ostream& os,const FirstClass& firstClass);


        //Static method to test class FirstClass
        static void UnitTestFirstClass();

        
};


class AC3Tier:public BerthClass
{
    private:
        static const double sLoadFactor;
        AC3Tier();
        ~AC3Tier();

    public:
        

        //Singleton AC3Tier
        static const AC3Tier& Type()
        {
            static const AC3Tier obj;
            return obj;
        }
        double GetLoadFactor() const;

         //Output Stream Overloading
        friend ostream& operator<<(ostream& os,const AC3Tier& ac3Tier);


        //Static method to test class AC3Tier
        static void UnitTestAC3Tier();

        
};


class Sleeper:public BerthClass
{
    private:
        static const double sLoadFactor;
        Sleeper();
        ~Sleeper();


    public:
        
        //Singleton Sleeper
        static const Sleeper& Type()
        {
            static const Sleeper obj;
            return obj;
        }
        double GetLoadFactor() const;

         //Output Stream Overloading
        friend ostream& operator<<(ostream& os,const Sleeper& sleeper);        

        //Static method to test class Sleeper
        static void UnitTestSleeper();
};


class ACChairCar:public SeatingClass
{
    private:
        static const double sLoadFactor;
        ACChairCar();
        ~ACChairCar();

    public:

        //Singleton ACChairCar
        static const ACChairCar& Type()
        {
            static const ACChairCar obj;
            return obj;
        }
        double GetLoadFactor() const;

        //Output Stream Overloading
        friend ostream& operator<<(ostream& os,const ACChairCar& acChairCar);

        //Static method to test classtACChairCar
        static void UnitTestACChairCar();
        
};

class SecondSitting:public SeatingClass
{
    private:
        static const double sLoadFactor;
        SecondSitting();
        ~SecondSitting();

    public:

        //Singleton SecondSitting
        static const SecondSitting& Type()
        {
            static const SecondSitting obj;
            return obj;
        }
        double GetLoadFactor() const;

        //Output Stream Overloading
        friend ostream& operator<<(ostream& os,const SecondSitting& secondSitting);

        //Static method to test class SecondSitting
        static void UnitTestSecondSitting();


};

#endif