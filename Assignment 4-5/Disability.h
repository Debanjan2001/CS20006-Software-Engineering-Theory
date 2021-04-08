/*---------------- 
Debanjan Saha
19CS30014
-----------------*/
#ifndef __DISABILITY_H
#define __DISABILITY_H

// ***** C++ Standard Library Headers
#include<iostream>
using namespace std;

// Forward declaration of templatized class
template<typename T>
class DisabilityTypes;  // Generic Disability type to generate specific Disabilitys

class Disability // Abstract Base Class
{ 
    private:
        const string& name_;  // Name of the Disability
        
        // Tag types - to instantiate the template
        // Note that these names are placeholders only and are not exposed outside the class
        // Also they are put inside the class for not cluttering the global namespace
        struct BlindType{};
        struct OrthopaedicType{};
        struct CancerType{};
        struct TBType{};
    
    protected:
        Disability(const string& name) : name_(name) {}
        virtual ~Disability() { }
        
    public:

        const string& GetName() const { return name_; }
        virtual const string& GetKey() const = 0; // Salutation specific to Disability
        
        
        // Enumerated types - the target sub-types
        typedef DisabilityTypes<BlindType> Blind;
        typedef DisabilityTypes<OrthopaedicType> Orthopaedic;
        typedef DisabilityTypes<CancerType> Cancer;
        typedef DisabilityTypes<TBType> TB;

};

// Specific Disability  types
template<typename T>
class DisabilityTypes : public Disability
{
    private:
        static const string sName;  // Respective name of the Disability
        static const string sKey;    // Respective salutation for the Disability
        
        DisabilityTypes(const string& name = DisabilityTypes<T>::sName) : Disability(name) { }
        ~DisabilityTypes() { }
    
    public:
        // Singleton object - placeholder for the respective type
        static const DisabilityTypes<T>& Type() 
        {
            static const DisabilityTypes<T> theObject;  // May be non-const for changeable behavior
            return theObject;
        }
        
        const string& GetKey() const           // Dynamic dispatch
        { return DisabilityTypes<T>::sKey; } // Salutation parametrized by static
};
  

#endif

