/*---------------- 
Debanjan Saha
19CS30014
-----------------*/

// ***** C++ Standard Library Headers
#include<iostream>
#include<string>
using namespace std;


// ***** Project Headers
#include "Station.h"
#include "Exceptions.h"


//Constructor with one parameter
Station::Station(const string& name): name_(name)
{}

string Station::GetName() const
{
    //return name of self(a Station)
    return name_;
}

const Station& Station::CreateStation(const string& name)
{
    if(name.length() == 0)
        throw Bad_Railways("Bad_Railways: Station with empty name can't be created.");
    
    Station* station = new Station(name);
    return *station;
}

//Destructor
Station::~Station()
{}

// Output Stream Overloading
ostream& operator<<(ostream& os,const Station& station)
{
    os<<station.GetName();
    return os;
}

void Station::UnitTestStation()
{
    cout<<endl;

    int success = 0,totTest=0;

    cout<<"CHECKING FOR POSITIVE TESTS\n"<<endl;
    
    try
    {
        Station s = Station::CreateStation("Delhi");
        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }
    catch(Bad_Railways& ex)
    {
        cout << ex.what() << '\n';
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;

    }

    try
    {
        Station s = Station::CreateStation("Delhi");
        if(s.GetName()!="Delhi")
            throw Bad_Railways("Bad_Railways: Station name do not match");
            
        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }
    catch(Bad_Railways& ex)
    {
        cout << ex.what() << '\n';
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;

    }


    cout<<endl;
    cout<<"CHECKING FOR NEGATIVE TESTS\n"<<endl;
    try
    {
        Station s = Station::CreateStation("");
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;
    }
    catch(Bad_Railways& ex)
    {
        cout<<ex.what()<<endl;
        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }

    cout<<endl;
    cout<<success<<" OUT OF "<<totTest<<" TESTS [PASSED]"<<endl;

}

