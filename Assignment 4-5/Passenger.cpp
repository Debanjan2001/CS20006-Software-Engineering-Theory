/*---------------- 
Debanjan Saha
19CS30014
-----------------*/

// ***** C++ Standard Library Headers
#include<iostream>
#include<string>
using namespace std;

// ***** Project Headers
#include "Passenger.h"
#include "Exceptions.h"

// Constructor
Passenger::Passenger(const string& fName,const string& mName,const string& lName,const string& aadhar,const Date& dob,const Gender& gender,const string& mobile,const Disability* disabilityType, const string& disabilityID ):
firstName_(fName),middleName_(mName),lastName_(lName),dateOfBirth_(dob),gender_(gender),aadhar_(aadhar),mobile_(mobile),disabilityID_(disabilityID),disabilityType_(disabilityType){};

const Passenger& Passenger::CreatePassenger(const string& fName ,const string& mName ,const string& lName , const Gender& gender,const string& aadhar,const Date& dob,const string& mobile,const Disability* disabilityType,const string& disabilityID)
{
    if(fName.length()==0 && lName.length() == 0 )
        throw Bad_Passenger("Bad_Passenger: Both First Name and Last Name empty");
    
    if(aadhar.length()!=12)
        throw Bad_Passenger("Bad_Passenger: Aadhar Number is not of length 12 digits ");

    for(int i=0;i<aadhar.length();i++)
    {
        if(aadhar[i]>'9' || aadhar[i]<'0' )
            throw Bad_Passenger("Bad_Passenger: Aadhar Number is not valid ");
    }

    if(mobile.length()!=0)
    {
        if(mobile.length()!=10)
            throw Bad_Passenger("Bad_Passenger: Mobile Number is not of length 10 digits ");

        for(int i=0;i<10;i++)
        {
            if(mobile[i]>'9' || mobile[i]<'0')
                throw Bad_Passenger("Bad_Passenger: Mobile Number is not valid");
        }
   }

    if( disabilityType!=NULL && disabilityID.length()==0)
        throw Bad_Passenger("Bad_Passenger: No disability ID provided by Passenger.");
   

    Passenger* p = new Passenger(fName,mName,lName,aadhar,dob,gender,mobile,disabilityType,disabilityID);
    return *p;
}

// Getter methods *****************************

const Date& Passenger::GetDateOfBirth() const
{
    return dateOfBirth_;
}

const string Passenger::GetName() const
{
    return firstName_+" "+ middleName_+" "+lastName_;
}

const string Passenger::GetDisabilityID() const
{
    return disabilityID_;
}

const Gender& Passenger::GetGender() const
{
    return gender_;
}

const Disability* Passenger::GetDisabilityType() const
{
    return disabilityType_;
}

// Output Stream overload   
ostream& operator<<(ostream& os,const Passenger& passenger)
{
    os<<"Passenger Info:"<<endl;
    os<<"Name: "<< passenger.GetName()<<endl;
    os<<"Gender: "<<passenger.GetGender().GetName()<<endl;
    os<<"Date of Birth: "<<passenger.GetDateOfBirth()<<endl;
    os<<"Aadhar no.: "<<passenger.aadhar_<<endl;
    if(passenger.mobile_.length()>0)
        os<<"Mobile No: "<<passenger.mobile_<<endl;
    
    if(passenger.GetDisabilityType()!=NULL)
    {
        os<<"Disability Type: "<<passenger.GetDisabilityType()->GetKey()<<endl;
        os<<"Disability ID: "<<passenger.GetDisabilityID()<<endl; 
    }
    return os;
}

//Destructor
Passenger::~Passenger()
{}

void Passenger::UnitTestPassenger()
{
     cout<<endl;

    int success = 0,totTest=0;

    cout<<"CHECKING FOR POSITIVE TESTS\n"<<endl;
    
    try
    {
        Passenger p = Passenger::CreatePassenger("Arpan","Dey","Sarkar",Gender::Male::Type(),"432768911196",Date::CreateDate(14,7,2001),"9830020322");
        Date dob = p.GetDateOfBirth();
        if( ( dob == Date::CreateDate(14,7,2001) ) ==false)
            throw Bad_Passenger("Bad_Passenger: Date of Birth Dont Match");

        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }
    catch(Bad_Passenger& ex)
    {
        cout << ex.what() << '\n';
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;
    }

    try
    {
        Passenger p = Passenger::CreatePassenger("Arpan","Dey","Sarkar",Gender::Male::Type(),"432768911196",Date::CreateDate(14,7,2001),"9830020322",&Disability::Cancer::Type(),"22153");
        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }
    catch(Bad_Passenger& ex)
    {
        cout << ex.what() << '\n';
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;

    }

    cout<<endl;
    cout<<"CHECKING FOR NEGATIVE TESTS\n"<<endl;
    try
    {
        Passenger p = Passenger::CreatePassenger("","","",Gender::Male::Type(),"432768911196",Date::CreateDate(14,7,2001),"9830020322",&Disability::Cancer::Type(),"22153");
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;
    }
    catch(Bad_Passenger& ex)
    {
        cout<<ex.what()<<endl;
        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }

    try
    {
        Passenger p = Passenger::CreatePassenger("Debanjan","","Saha",Gender::Male::Type(),"43276891196",Date::CreateDate(14,7,2001),"9830020322",&Disability::Cancer::Type(),"22153");
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;
    }
    catch(Bad_Passenger& ex)
    {
        cout<<ex.what()<<endl;
        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }

    try
    {
        Passenger p = Passenger::CreatePassenger("Debanjan","","Saha",Gender::Male::Type(),"432768911a96",Date::CreateDate(14,7,2001),"9830020322",&Disability::Cancer::Type(),"22153");
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;
    }
    catch(Bad_Passenger& ex)
    {
        cout<<ex.what()<<endl;
        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }

    try
    {
        Passenger p = Passenger::CreatePassenger("Debanjan","","Saha",Gender::Male::Type(),"432768911296",Date::CreateDate(14,7,2001),"983032",&Disability::Cancer::Type(),"22153");
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;
    }
    catch(Bad_Passenger& ex)
    {
        cout<<ex.what()<<endl;
        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }

    try
    {
        Passenger p = Passenger::CreatePassenger("Debanjan","","Saha",Gender::Male::Type(),"432768911296",Date::CreateDate(14,7,2001),"980203sas4",&Disability::Cancer::Type(),"22153");
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;
    }
    catch(Bad_Passenger& ex)
    {
        cout<<ex.what()<<endl;
        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }

    try
    {
        Passenger p = Passenger::CreatePassenger("Debanjan","","Saha",Gender::Male::Type(),"432768911296",Date::CreateDate(14,7,2001),"9802030004",&Disability::Cancer::Type());
        cout<<"Sub-Test "<< ++totTest<<" [FAILED]"<<endl;
    }
    catch(Bad_Passenger& ex)
    {
        cout<<ex.what()<<endl;
        cout<<"Sub-Test "<< ++totTest<<" [PASSED]"<<endl;
        success++;
    }

    cout<<endl;
    cout<<success<<" OUT OF "<<totTest<<" TESTS [PASSED]"<<endl;

}

