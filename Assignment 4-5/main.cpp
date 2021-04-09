#include<iostream>
using namespace std;

#include "Gender.h"
#include "Passenger.h"
#include "Booking.h"
#include "BookingClasses.h"
#include "BookingCategory.h"
#include "Date.h"
#include "Station.h"
#include "Railways.h"
#include "Exceptions.h"
#include "Disability.h"


int main(){
    // try{
    //     Station a("Ari");
    //     if(a.GetName()!="Aria"){
    //         Bad_Station error;
    //         throw error;
    //     }
    // }catch(Bad_Station& error){
    //     cout<<error.what()<<endl;
    // }
    // Bad_Station error;
    // const Railways& ind = (Railways::IndianRailways());
    // cout<<"Okay"<<endl;
    // const Station* a = (ind).GetStation("Delhi");
    // cout<< a->GetName();
    // cout<<1<<endl;
    // cout<< a<<endl;

    // Date a = Date::CreateDate(31,4,2001);

    // cout<<a<<endl;
    // const Gender* g = &Gender::Male::Type();
    // cout<< Gender::IsMale(*g)<<endl;

    // const Disability* d = &Disability::Cancer::Type();
    // cout<< d->GetKey() <<endl;


    // cout<< BookingClasses::AC2Tier::Type().GetName()<<endl;

    // try{
    //     Station a = Station::CreateStation("sas");
    //     cout<<a.GetName()<<endl;
    //     cout<<a.GetName()<<endl;
    // }catch(Bad_Railways& err)
    // {
    //     cout<<err.what()<<endl;
    // }

    // Passenger p1 = Passenger::CreatePassenger("apan","dey","sarkar",Gender::Male::Type(),"100",Date::CreateDate(14,7,2001),"100");
    // Passenger p2 = Passenger::CreatePassenger("arpita","","sarkar",Gender::Female::Type(),"100",Date::CreateDate(14,5,1979),"100",&Disability::Cancer::Type(),"20");
    // cout<< a.GetDisabilityType().GetKey()<<endl;
    // cout<<a.GetGender().GetName()<<endl;

    // const Station* a = Railways::IndianRailways().GetStation("Delhi");
    // cout<<a<<endl; 

    // cout<<Railways::IndianRailways().GetDistance("Delhi","Mumbai");
    // Railways::IndianRailways().AddDistance("Chennai","Kolkata",1659); //remove const for this.
    
    // const BookingClasses& a = BookingClasses::AC2Tier::Type();
    // cout<<a.GetName()<<endl;

    // const BookingCategory&b = SeniorCitizen::Type();
    // cout<<b.CalculateFare(a,BookingClasses::AC2Tier::Type())<<endl; 
    // cout<<b<<endl;
    // const Railways& rail = Railways::IndianRailways();
    // Booking a1 = Booking::CreateBooking(*rail.GetStation("Delhi"),Station::CreateStation("Mumbai"),Date::CreateDate(9,4,2021),Date::CreateDate(24,9,2021),BookingClasses::AC3Tier::Type(),Tatkal::Type(),p1);
    // Booking a2 = Booking::CreateBooking(*rail.GetStation("Delhi"),Station::CreateStation("Mumbai"),Date::CreateDate(9,4,2021),Date::CreateDate(20,9,2021),BookingClasses::ACFirstClass::Type(),Divyaang::Type(),p2);

    // vector<Booking*>::iterator it;
    // for (it = Booking::sBookings.begin(); it < Booking::sBookings.end(); ++it) {
    //     cout <<(*(*it))<<endl;
    // }

    
   


    return 0;
}