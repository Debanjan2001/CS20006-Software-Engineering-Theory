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

// Forward declaration
template<typename T>
class BookingClassesTypes;

// Abstract Base Class
class BookingClasses
{
	const string name_;
	const bool isAc_, isSeating_, isLuxury_;
	
	// Types of BookingClasses.
	struct ACFirstClassType{};
	struct FirstClassType{};
	struct ExecutiveChairCarType{};
	struct AC2TierType{};
	struct AC3TierType{};
	struct ACChairCarType{};
	struct SleeperType{};
	struct SecondSittingType{};


protected:

	BookingClasses(const string& name, const bool isAc, const bool isSeating, const bool isLuxury): name_(name), isLuxury_(isLuxury), isAc_(isAc), isSeating_(isSeating){}
	virtual ~BookingClasses() {};
    
public:

	// All Getter methods required for further processing in booking
	const string GetName() const {	return name_;}
	virtual const double GetLoadFactor() const = 0;
	virtual const int GetNumberOfTiers() const = 0;
	virtual const double GetReservationCharge() const = 0;
	
	const bool& IsAC() const{	return isAc_;}
	const bool& IsSeating() const{	return isSeating_;}
	const bool& IsLuxury() const{	return isLuxury_;}
	
	virtual const int GetMinDistance() const = 0;
	virtual const double GetMinTatkalCharge() const = 0 ;
	virtual const double GetMaxTatkalCharge() const = 0 ;
	
	// Type defining 
	typedef BookingClassesTypes<ACFirstClassType> ACFirstClass;
	typedef BookingClassesTypes<FirstClassType> FirstClass;
	typedef BookingClassesTypes<ExecutiveChairCarType> ExecutiveChairCar;
	typedef BookingClassesTypes<AC2TierType> AC2Tier;
	typedef BookingClassesTypes<AC3TierType> AC3Tier;
	typedef BookingClassesTypes<ACChairCarType> ACChairCar;
	typedef BookingClassesTypes<SleeperType> Sleeper;
	typedef BookingClassesTypes<SecondSittingType> SecondSitting;

};


// Implementation of parametric hierarchy
template<typename T>
class BookingClassesTypes: public BookingClasses{
	private:
		static const string sName;
		static const int sNumTiers,sMinDistance;
		static const double sReservationCharge,sMinTatkalCharge,sMaxTatkalCharge;
		static const bool sIsAc, sIsSeating,sIsLuxury;
		static const double sLoadFactor;

		BookingClassesTypes(const string& name = BookingClassesTypes<T>::sName, const bool isAc = BookingClassesTypes<T>::sIsAc,const bool isLuxury = BookingClassesTypes<T>::sIsLuxury, const bool isSeating = BookingClassesTypes<T>::sIsSeating):
			BookingClasses(name, isAc, isSeating, isLuxury){}
		~BookingClassesTypes() {}

	public:

		//Static constant Meyer's Singleton
		static const BookingClassesTypes<T>& Type(){
			static const BookingClassesTypes<T> theObject;
			return theObject;
		}
		
		// Getter methods overloaded
		const int GetMinDistance() const { return sMinDistance; }
		const double GetMinTatkalCharge() const { return sMinTatkalCharge; }
		const double GetMaxTatkalCharge() const { return sMaxTatkalCharge; }
		const int GetNumberOfTiers() const { return sNumTiers; };
		const double GetReservationCharge() const { return sReservationCharge; };
		const double GetLoadFactor() const{	return BookingClassesTypes<T>::sLoadFactor;}

		
};


#endif