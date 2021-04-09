/*---------------- 
Debanjan Saha
19CS30014
-----------------*/
#ifndef __BOOKINGCATEGORY_H
#define __BOOKINGCATEGORY_H

// ***** C++ Standard Library Headers
#include<iostream>
#include<string>
#include<map>
using namespace std;

// Project Headers
#include "Passenger.h"
#include "BookingClasses.h"
#include "Disability.h"

class BookingCategory
{
    private:
        const string name_;
    protected:
        // Protected Constructor and Destructor for not allowing instantiation
        BookingCategory(const string& name);
        virtual ~BookingCategory() = 0;

        // Base Fare per km
        static const double sBaseFarePerKM;

    public:
        const string GetName() const;
        virtual const int CalculateFare(const Passenger& passenger,const BookingClasses& bookingClass,int distance) const= 0;
        virtual const bool IsEligible(const Passenger& passenger,const Date& dateOfReservation,const Date& dateOfJourney)const = 0;

        friend ostream& operator<<(ostream& os, const BookingCategory& bookingCategory);
};

class General: public BookingCategory
{
    private:
        // Private Constructor and Destructor for not allowing instantiation
        General();
        ~General();

    public:
        // Overloading Getters
        const int CalculateFare(const Passenger& passenger,const BookingClasses& bookingClass,int distance) const;
        const bool IsEligible(const Passenger& passenger,const Date& dateOfReservation,const Date& dateOfJourney) const;
		
        //Static constant Meyer's Singleton
        static const General& Type()
        {
            static const General theObject;
            return theObject;
        }
};

// Abstract Base Class
class ConcessionCategory: public BookingCategory
{
    protected:
        // Protected Constructor and Destructor for not allowing instantiation
        ConcessionCategory(const string&  name);
        virtual ~ConcessionCategory() = 0;
};

// Abstract Base Class
class PriorityCategory: public BookingCategory
{
   protected:
        // Protected Constructor and Destructor for not allowing instantiation
        PriorityCategory(const string&  name);
        virtual ~PriorityCategory() = 0;

};

// Concrete Booking Category
class SeniorCitizen: public ConcessionCategory
{
    private:
        // static constants for male and female for this booking category
        static const double sMaleConcession;
        static const double sFemaleConcession;

        // Private Constructor and Destructor for not allowing instantiation
        SeniorCitizen();
        ~SeniorCitizen();

    public:
        // Overloading Getters
        const int CalculateFare(const Passenger& passenger,const BookingClasses& bookingClass,int distance) const;
        const bool IsEligible(const Passenger& passenger,const Date& dateOfReservation,const Date& dateOfJourney) const;
        
        //Static constant Meyer's Singleton
        static const SeniorCitizen& Type()
        {
            static const SeniorCitizen theObject;
            return theObject;
        }
};

// Concrete Booking Category
class Divyaang: public ConcessionCategory
{
    private:
        // Master data for concession based on disability and booking class
        static map<pair<const Disability*,const BookingClasses*>,double> sDivyaangMatrix; 
       
        // Private Constructor and Destructor for not allowing instantiation
        Divyaang();
        ~Divyaang();
    
    public:
        // Overloading Getters
        const int CalculateFare(const Passenger& passenger,const BookingClasses& bookingClass,int distance) const;
        const bool IsEligible(const Passenger& passenger,const Date& dateOfReservation,const Date& dateOfJourney) const;
       
        //Static constant Meyer's Singleton
        static const Divyaang& Type()
        {
            static const Divyaang theObject;
            return theObject;
        }

};

// Concrete Booking Category
class Ladies: public ConcessionCategory
{
    private:
        // Private Constructor and Destructor for not allowing instantiation
        Ladies();
        ~Ladies();

    public:
        // Overloading Getters
        const int CalculateFare(const Passenger& passenger,const BookingClasses& bookingClass,int distance) const;
        const bool IsEligible(const Passenger& passenger,const Date& dateOfReservation,const Date& dateOfJourney) const;
        
        //Static constant Meyer's Singleton
        static const Ladies& Type()
        {
            static const Ladies theObject;
            return theObject;
        }

};

// Concrete Booking Category
class Tatkal: public PriorityCategory
{
    private:
        // Private Constructor and Destructor for not allowing instantiation
        Tatkal();
        ~Tatkal();

    public:
        // Overloading Getters
        const int CalculateFare(const Passenger& passenger,const BookingClasses& bookingClass,int distance) const;
        const bool IsEligible(const Passenger& passenger,const Date& dateOfReservation,const Date& dateOfJourney) const;
       
        //Static constant Meyer's Singleton
        static const Tatkal& Type()
        {
            static const Tatkal theObject;
            return theObject;
        }

};

// Concrete Booking Category
class PremiumTatkal: public PriorityCategory
{
    private:
        // Private Constructor and Destructor for not allowing instantiation
        PremiumTatkal();
        ~PremiumTatkal();

    public:

        // Overloading Getters
        const int CalculateFare(const Passenger& passenger,const BookingClasses& bookingClass,int distance) const;
        const bool IsEligible(const Passenger& passenger,const Date& dateOfReservation,const Date& dateOfJourney) const;
        
        //Static constant Meyer's Singleton
        static const PremiumTatkal& Type()
        {
            static const PremiumTatkal theObject;
            return theObject;
        }
};


#endif 