/*---------------- 
Debanjan Saha
19CS30014
-----------------*/

#include<iostream>
#include<map>

using namespace std;

#include "BookingCategory.h"

BookingCategory::BookingCategory(const string& name): name_(name){};

BookingCategory::~BookingCategory() {};

const string BookingCategory::GetName() const
{
    return name_;
}

ostream& operator<<(ostream& os, const BookingCategory& bookingCategory)
{
    os<<bookingCategory.GetName();
    return os;
}

General::General():BookingCategory("General"){};

General::~General(){};

ConcessionCategory::ConcessionCategory(const string&name):BookingCategory(name){};

ConcessionCategory::~ConcessionCategory(){};

SeniorCitizen::SeniorCitizen():ConcessionCategory("Senior Citizen"){};

SeniorCitizen::~SeniorCitizen(){};

Ladies::Ladies():ConcessionCategory("Ladies"){};

Ladies::~Ladies(){};

PriorityCategory::PriorityCategory(const string& name):BookingCategory(name){};

PriorityCategory::~PriorityCategory(){};

Tatkal::Tatkal():PriorityCategory("Tatkal"){};

Tatkal::~Tatkal(){};

PremiumTatkal::PremiumTatkal():PriorityCategory("Premium Tatkal"){};

PremiumTatkal::~PremiumTatkal(){};

map<pair<const Disability*,const BookingClasses*>,double> Divyaang::sDivyaangMatrix;

Divyaang::Divyaang():ConcessionCategory("Divyaang")
{
    sDivyaangMatrix[make_pair( &Disability::Blind::Type(),&BookingClasses::ACFirstClass::Type() )] =  0.50; 
    sDivyaangMatrix[make_pair( &Disability::Blind::Type(),&BookingClasses::ExecutiveChairCar::Type() )] =  0.75; 
    sDivyaangMatrix[make_pair( &Disability::Blind::Type(),&BookingClasses::AC2Tier::Type() )] =  0.50; 
    sDivyaangMatrix[make_pair( &Disability::Blind::Type(),&BookingClasses::FirstClass::Type() )] =  0.75; 
    sDivyaangMatrix[make_pair( &Disability::Blind::Type(),&BookingClasses::AC3Tier::Type() )] =  0.75; 
    sDivyaangMatrix[make_pair( &Disability::Blind::Type(),&BookingClasses::ACChairCar::Type() )] =  0.75; 
    sDivyaangMatrix[make_pair( &Disability::Blind::Type(),&BookingClasses::Sleeper::Type() )] =  0.75; 
    sDivyaangMatrix[make_pair( &Disability::Blind::Type(),&BookingClasses::SecondSitting::Type() )] =  0.75; 

    sDivyaangMatrix[make_pair( &Disability::Orthopaedic::Type(),&BookingClasses::ACFirstClass::Type() )] =  0.50; 
    sDivyaangMatrix[make_pair( &Disability::Orthopaedic::Type(),&BookingClasses::ExecutiveChairCar::Type() )] =  0.75; 
    sDivyaangMatrix[make_pair( &Disability::Orthopaedic::Type(),&BookingClasses::AC2Tier::Type() )] =  0.50; 
    sDivyaangMatrix[make_pair( &Disability::Orthopaedic::Type(),&BookingClasses::FirstClass::Type() )] =  0.75; 
    sDivyaangMatrix[make_pair( &Disability::Orthopaedic::Type(),&BookingClasses::AC3Tier::Type() )] =  0.75; 
    sDivyaangMatrix[make_pair( &Disability::Orthopaedic::Type(),&BookingClasses::ACChairCar::Type() )] =  0.75; 
    sDivyaangMatrix[make_pair( &Disability::Orthopaedic::Type(),&BookingClasses::Sleeper::Type() )] =  0.75; 
    sDivyaangMatrix[make_pair( &Disability::Orthopaedic::Type(),&BookingClasses::SecondSitting::Type() )] =  0.75; 

    sDivyaangMatrix[make_pair( &Disability::Cancer::Type(),&BookingClasses::ACFirstClass::Type() )] =  0.50; 
    sDivyaangMatrix[make_pair( &Disability::Cancer::Type(),&BookingClasses::ExecutiveChairCar::Type() )] =  0.75; 
    sDivyaangMatrix[make_pair( &Disability::Cancer::Type(),&BookingClasses::AC2Tier::Type() )] =  0.50; 
    sDivyaangMatrix[make_pair( &Disability::Cancer::Type(),&BookingClasses::FirstClass::Type() )] =  0.75; 
    sDivyaangMatrix[make_pair( &Disability::Cancer::Type(),&BookingClasses::AC3Tier::Type() )] =  1.00; 
    sDivyaangMatrix[make_pair( &Disability::Cancer::Type(),&BookingClasses::ACChairCar::Type() )] =  1.00; 
    sDivyaangMatrix[make_pair( &Disability::Cancer::Type(),&BookingClasses::Sleeper::Type() )] =  1.00; 
    sDivyaangMatrix[make_pair( &Disability::Cancer::Type(),&BookingClasses::SecondSitting::Type() )] =  1.00; 

    sDivyaangMatrix[make_pair( &Disability::TB::Type(),&BookingClasses::ACFirstClass::Type() )] =  0.00; 
    sDivyaangMatrix[make_pair( &Disability::TB::Type(),&BookingClasses::ExecutiveChairCar::Type() )] =  0.00; 
    sDivyaangMatrix[make_pair( &Disability::TB::Type(),&BookingClasses::AC2Tier::Type() )] =  0.00; 
    sDivyaangMatrix[make_pair( &Disability::TB::Type(),&BookingClasses::FirstClass::Type() )] =  0.75; 
    sDivyaangMatrix[make_pair( &Disability::TB::Type(),&BookingClasses::AC3Tier::Type() )] =  0.00; 
    sDivyaangMatrix[make_pair( &Disability::TB::Type(),&BookingClasses::ACChairCar::Type() )] =  0.00; 
    sDivyaangMatrix[make_pair( &Disability::TB::Type(),&BookingClasses::Sleeper::Type() )] =  0.75; 
    sDivyaangMatrix[make_pair( &Disability::TB::Type(),&BookingClasses::SecondSitting::Type() )] =  0.75; 

};

Divyaang::~Divyaang(){};

const double SeniorCitizen::sMaleConcession = 0.40;
const double SeniorCitizen::sFemaleConcession = 0.50;

const bool General::IsEligible(const Passenger& passenger,const Date& dateOfReservation,const Date& dateOfJourney) const
{
    return true;
}

const bool SeniorCitizen::IsEligible(const Passenger& passenger,const Date& dateOfReservation,const Date& dateOfJourney) const
{
    int age = dateOfReservation.ComputeAge(passenger.GetDateOfBirth());
    if( Gender::IsMale(passenger.GetGender()) && age>= 60)
        return true;
    else if( Gender::IsMale(passenger.GetGender()) == false && age>=58)
        return true;

    return false;
}

const bool Ladies::IsEligible(const Passenger& passenger,const Date& dateOfReservation,const Date& dateOfJourney) const
{
    int age = dateOfReservation.ComputeAge(passenger.GetDateOfBirth());
    if(  Gender::IsMale(passenger.GetGender()) && age<12)
        return true;
    else if( Gender::IsMale(passenger.GetGender()) == false)
        return true;

    return false;
}

const bool Divyaang::IsEligible(const Passenger& passenger,const Date& dateOfReservation,const Date& dateOfJourney) const
{
    if(  passenger.GetDisabilityType() != NULL )
        return true;

    return false;
}


const bool Tatkal::IsEligible(const Passenger& passenger,const Date& dateOfReservation, const Date& dateOfJourney) const
{
    //
    return false;
}


const bool PremiumTatkal::IsEligible(const Passenger& passenger,const Date& dateOfReservation, const Date& dateOfJourney) const
{
    //
    return false;
}



const int General::CalculateFare(const Passenger& passenger,const BookingClasses& bookingClass) const
{
    return 0;
}

const int SeniorCitizen::CalculateFare(const Passenger& passenger,const BookingClasses& bookingClass) const
{
    return 0;
}

const int Ladies::CalculateFare(const Passenger& passenger,const BookingClasses& bookingClass) const
{
    return 0;
}

const int Divyaang::CalculateFare(const Passenger& passenger,const BookingClasses& bookingClass) const
{
    return 0;
}

const int Tatkal::CalculateFare(const Passenger& passenger,const BookingClasses& bookingClass) const
{
    return 0;
}

const int PremiumTatkal::CalculateFare(const Passenger& passenger,const BookingClasses& bookingClass) const
{
    return 0;
}








