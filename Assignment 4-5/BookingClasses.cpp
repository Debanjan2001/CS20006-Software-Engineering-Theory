/*---------------- 
Debanjan Saha
19CS30014
-----------------*/

// ***** C++ Standard Library Headers
#include<iostream>
#include<string>
using namespace std;

// ***** Project Headers
#include "BookingClasses.h"

template<>
const string BookingClasses::ACFirstClass::sName = "AC First Class";
template<>
const double BookingClasses::ACFirstClass::sLoadFactor = 6.50;
template<>
const bool BookingClasses::ACFirstClass::sIsSeating = false;
template<>
const bool BookingClasses::ACFirstClass::sIsAc = true;
template<>
const int BookingClasses::ACFirstClass::sNumTiers = 2;
template<>
const bool BookingClasses::ACFirstClass::sIsLuxury = true;
template<>
const double BookingClasses::ACFirstClass::sReservationCharge = 60.0;


template<>
const string BookingClasses::ExecutiveChairCar::sName = "Executive Chair Car";
template<>
const double BookingClasses::ExecutiveChairCar::sLoadFactor = 5.00;
template<>
const bool BookingClasses::ExecutiveChairCar::sIsSeating = true;
template<>
const bool BookingClasses::ExecutiveChairCar::sIsAc = true;
template<>
const int BookingClasses::ExecutiveChairCar::sNumTiers = 0;
template<>
const bool BookingClasses::ExecutiveChairCar::sIsLuxury = true;
template<>
const double BookingClasses::ExecutiveChairCar::sReservationCharge = 60.0;



template<>
const string BookingClasses::AC2Tier::sName = "AC 2 Tier";
template<>
const double BookingClasses::AC2Tier::sLoadFactor = 4.00;
template<>
const bool BookingClasses::AC2Tier::sIsSeating = false;
template<>
const bool BookingClasses::AC2Tier::sIsAc = true;
template<>
const int BookingClasses::AC2Tier::sNumTiers = 2;
template<>
const bool BookingClasses::AC2Tier::sIsLuxury = false;
template<>
const double BookingClasses::AC2Tier::sReservationCharge = 50.0;



template<>
const string BookingClasses::FirstClass::sName = "First Class";
template<>
const double BookingClasses::FirstClass::sLoadFactor = 3.00;
template<>
const bool BookingClasses::FirstClass::sIsSeating = false;
template<>
const bool BookingClasses::FirstClass::sIsAc = false;
template<>
const int BookingClasses::FirstClass::sNumTiers = 2;
template<>
const bool BookingClasses::FirstClass::sIsLuxury = true;
template<>
const double BookingClasses::FirstClass::sReservationCharge = 50.0;



template<>
const string BookingClasses::AC3Tier::sName = "AC 3 Tier";
template<>
const double BookingClasses::AC3Tier::sLoadFactor = 2.50;
template<>
const bool BookingClasses::AC3Tier::sIsSeating = false;
template<>
const bool BookingClasses::AC3Tier::sIsAc = true;
template<>
const int BookingClasses::AC3Tier::sNumTiers = 3;
template<>
const bool BookingClasses::AC3Tier::sIsLuxury = false;
template<>
const double BookingClasses::AC3Tier::sReservationCharge = 40.0;



template<>
const string BookingClasses::ACChairCar::sName = "AC Chair Car";
template<>
const double BookingClasses::ACChairCar::sLoadFactor = 2.00;
template<>
const bool BookingClasses::ACChairCar::sIsSeating = true;
template<>
const bool BookingClasses::ACChairCar::sIsAc = true;
template<>
const int BookingClasses::ACChairCar::sNumTiers = 0;
template<>
const bool BookingClasses::ACChairCar::sIsLuxury = false;
template<>
const double BookingClasses::ACChairCar::sReservationCharge = 40.0;



template<>
const string BookingClasses::Sleeper::sName = "Sleeper";
template<>
const double BookingClasses::Sleeper::sLoadFactor = 1.00;
template<>
const bool BookingClasses::Sleeper::sIsSeating = false;
template<>
const bool BookingClasses::Sleeper::sIsAc = false;
template<>
const int BookingClasses::Sleeper::sNumTiers = 3;
template<>
const bool BookingClasses::Sleeper::sIsLuxury = false;
template<>
const double BookingClasses::Sleeper::sReservationCharge = 20.0;


template<>
const string BookingClasses::SecondSitting::sName = "Second Sitting";
template<>
const double BookingClasses::SecondSitting::sLoadFactor = 0.60;
template<>
const bool BookingClasses::SecondSitting::sIsSeating = true;
template<>
const bool BookingClasses::SecondSitting::sIsAc = false;
template<>
const int BookingClasses::SecondSitting::sNumTiers = 0;
template<>
const bool BookingClasses::SecondSitting::sIsLuxury = false;
template<>
const double BookingClasses::SecondSitting::sReservationCharge = 10.0;





