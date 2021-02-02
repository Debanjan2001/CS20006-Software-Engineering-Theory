#ifndef FRACTION_HXX
#define FRACTION_HXX

#include<iostream>
#include<stdlib.h>
using namespace std;

class Fraction
{
    private:
        int p;  //Numerator
        unsigned int q; // Denominator
        
        void Normalise();   // Utility function to normalise values of p and q.
        inline static int precision();  //static utility function to return precision for floating point numbers.
        static int gcd(int ,int);   //static utility function to calculate gcd of two integers. 
        inline static int lcm(int, int);    //static utility function to calculate lcm of two integers. 

    public:

    //---Constructor---

        Fraction();          //Constructor without parameters
        Fraction(int);       //Constructor with one integer as parameter (Numerator)
        Fraction(int, int);  //Constructor with Two integers as parameters (Numerator and Denominator)
        Fraction(double);    //Constructor with One double as parameter (Numerator)
        
    
    //---Copy Constructor and Copy Assignment Constructor--

        Fraction(const Fraction &); //Copy Constructor with reference to a constant object that is to be copied.
        Fraction& operator=(const Fraction &);  //Copy Assignment Operator for assignment to constant object. Return by reference


    //---Unary Arithmetic Operators---

        Fraction operator-(); //Unary Minus , return by value
        Fraction operator+(); //Unary Plus , return by value
        Fraction operator++();     //Pre-Increment, return by value
        Fraction operator++(int);  //Post-Increment, return by value
        Fraction operator--();   //Pre-Decrement, return by value
        Fraction operator--(int);   //Post-Decrement, return by value


    //---Binary Arithmetic Operators---

        friend Fraction operator+(const Fraction&,const Fraction&);  //Addition of two non-modifiable Fraction class objects, return by value 
        friend Fraction operator-(const Fraction&,const Fraction&);  //Subtraction of two non-modifiable Fraction class objects, return by value 
        friend Fraction operator*(const Fraction&,const Fraction&);  //Multiplication of two non-modifiable Fraction class objects, return by value 
        friend Fraction operator/(const Fraction&,const Fraction&);  //Division of two non-modifiable Fraction class objects, return by value 
        friend Fraction operator%(const Fraction&,const Fraction&);  //Remainder of two non-modifiable Fraction class objects, return by value 


    //---Binary Relational Operators---

        bool operator==(const Fraction&);  //Equality, return by boolean value
        bool operator!=(const Fraction&);  //Inequality,return by boolean value
        bool operator<(const Fraction&);   //Less than, return by boolean value
        bool operator<=(const Fraction&);  //Less than Equal to, return by boolean value
        bool operator>(const Fraction&);   //Greater than, return by boolean value
        bool operator>=(const Fraction&);  //Greater than Equal to, return by boolean value

    //---Special Operator---
        Fraction operator!();   // Inversion Operator for a Fraction Class object. Return by value.
    

    //---I/O Operators---
        friend inline istream & operator>>(istream &,Fraction&);  //Input stream overloading.return by reference
        friend inline ostream & operator<<(ostream &,const Fraction&); //Output Stream overloading. return by reference.

    //---Static Constants of UDT---
        static const Fraction sc_fUnity; //static constant Unity of Fraction Data Type
        static const Fraction sc_fZero;  //static constant Zero of Fraction Data type

    //---Destructor---
        ~Fraction(); 
};


// Returns a precision value of 100000. Inlined for minimising overhead calls.
inline int Fraction::precision()
{
    return 100000;
}


// Returns absolute value of lcm of two integers. Inlined for optimisation.
inline int Fraction::lcm(int a ,int b)
{
    return abs((a*b)/gcd(a,b));
}


// Reads two consecutive integers as a Fraction Class Object from input stream.
//Inlined for optimisation.
inline istream & operator>>(istream& in,Fraction& f)
{
    in>>f.p>>f.q;
    f.Normalise();
    return in;
}


// Prints numerator and denominator of a Fraction Class Object in a formatted way to output stream.
//Inlined for optimisation.
inline ostream & operator<<(ostream& out,const Fraction& f)
{
    if(f.q == 1)
    {
        out<< f.p;
    }
    else
    {
        out<< f.p <<" / "<< f.q ;
    }
    return out;
}

#endif