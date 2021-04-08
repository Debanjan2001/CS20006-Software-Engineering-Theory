#include<iostream>
using namespace std;

#include "Gender.h"
#include "Passenger.h"
#include "Booking.h"
#include "BookingClasses.h"
#include "Date.h"
#include "Station.h"
#include "Railways.h"
#include "Exceptions.h"


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
    const Railways& ind = (Railways::IndianRailways());
    cout<<"Okay"<<endl;
    const Station* a = (ind).GetStation("Delhi");
    cout<< a->GetName();
    cout<<1<<endl;
    // cout<< a<<endl;
    
    return 0;
}