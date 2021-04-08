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

#include "Passenger.h"
#include "BookingClasses.h"
#include "Disability.h"

class BookingCategory
{
    private:
        const string name_;
    protected:
        BookingCategory(const string name);
        virtual ~BookingCategory() = 0;

    public:
        const string GetName() const;
        virtual const int CalculateFare(const Passenger& passenger,const BookingClasses& bookingClass) const= 0;
        virtual const bool IsEligible(const Passenger& passenger,const Date& dateOfReservation,const Date& dateOfJourney)const = 0;

        friend ostream& operator<<(ostream& os, const BookingCategory& bookingCategory);
};

class General: public BookingCategory
{
    private:
        General();
        ~General();

    public:
        const int CalculateFare(const Passenger& passenger,const BookingClasses& bookingClass) const;
        const bool IsEligible(const Passenger& passenger,const Date& dateOfReservation,const Date& dateOfJourney) const;
        static const General& Type()
        {
            static const General theObject;
            return theObject;
        }
};

class ConcessionCategory: public BookingCategory
{
    protected:
        ConcessionCategory(const string  name);
        virtual ~ConcessionCategory() = 0;
};

class PriorityCategory: public BookingCategory
{
   protected:
        PriorityCategory(const string  name);
        virtual ~PriorityCategory() = 0;

};

class SeniorCitizen: public ConcessionCategory
{
    private:
        static const double sMaleConcession;
        static const double sFemaleConcession;

        SeniorCitizen();
        ~SeniorCitizen();

    public:
        const int CalculateFare(const Passenger& passenger,const BookingClasses& bookingClass) const;
        const bool IsEligible(const Passenger& passenger,const Date& dateOfReservation,const Date& dateOfJourney) const;
        static const SeniorCitizen& Type()
        {
            static const SeniorCitizen theObject;
            return theObject;
        }
};

class Divyaang: public ConcessionCategory
{
    private:
        static map<pair<const Disability*,const BookingClasses*>,double> sDivyaangMatrix; 
        Divyaang();
        ~Divyaang();
    
    public:
        const int CalculateFare(const Passenger& passenger,const BookingClasses& bookingClass) const;
        const bool IsEligible(const Passenger& passenger,const Date& dateOfReservation,const Date& dateOfJourney) const;
        static const Divyaang& Type()
        {
            static const Divyaang theObject;
            return theObject;
        }

};

class Ladies: public ConcessionCategory
{
    private:
        Ladies();
        ~Ladies();

    public:
        const int CalculateFare(const Passenger& passenger,const BookingClasses& bookingClass) const;
        const bool IsEligible(const Passenger& passenger,const Date& dateOfReservation,const Date& dateOfJourney) const;
        static const Ladies& Type()
        {
            static const Ladies theObject;
            return theObject;
        }

};

class Tatkal: public PriorityCategory
{
    private:
        Tatkal();
        ~Tatkal();

    public:
        const int CalculateFare(const Passenger& passenger,const BookingClasses& bookingClass) const;
        const bool IsEligible(const Passenger& passenger,const Date& dateOfReservation,const Date& dateOfJourney) const;
        static const Tatkal& Type()
        {
            static const Tatkal theObject;
            return theObject;
        }

};

class PremiumTatkal: public PriorityCategory
{
    private:
        PremiumTatkal();
        ~PremiumTatkal();

    public:
        const int CalculateFare(const Passenger& passenger,const BookingClasses& bookingClass) const;
        const bool IsEligible(const Passenger& passenger,const Date& dateOfReservation,const Date& dateOfJourney) const;
        static const PremiumTatkal& Type()
        {
            static const PremiumTatkal theObject;
            return theObject;
        }
};


#endif 