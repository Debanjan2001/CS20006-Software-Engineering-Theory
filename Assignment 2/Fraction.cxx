#include<iostream>
#include<stdlib.h>  
using namespace std;

#include "Fraction.hxx"

//gcd takes two integers as input and returns absolute value of their gcd
//Uses Euclidean algorithm to calculate gcd.
int Fraction::gcd(int a, int b)
{
    a = abs(a),b = abs(b);
    if(b == 0)
        return a;
    if(a == 0)
    {
        return b;
    }
    return gcd(b%a,a);
} 

//Divides by Common factor of numerator and denominator
//Also sets denominator to 1 if numerator is 0.
void Fraction::Normalise()
{
    int g = gcd(p,q);
    p /= g;
    q /= g;

    if( p == 0 )
        q = 1;
    
} 

//Constructor with no Parameter 
//sets numerator and denominator to 1 
Fraction::Fraction()
{
    p = 1;
    q = 1;
}

//Constructor with 1 integer parameter m
//Sets numerator to m.(denominator = 1 by default)
Fraction::Fraction(int m)
{
    p = m;
    q = 1;
}

//Constructor with 2 integer parameters m,n
//Sets numerator to m,denominator to n and normalises.
// if n=0,it exits since it is invalid.if n<0, change signs of both numerator and denominator
//if m = 0, set n = 1 
Fraction::Fraction(int m,int n)
{
   if(n==0)
   {

       cout<<" Error: Can't create a fraction with denominator = 0."<<endl;
       exit(1);
   }
   else if(n<0)
   {
       p = -m;
       q = -n;
       Normalise();
   }
   else if(m==0)
   {
       p = 0;
       q = 1;
   }
   else
   {
       p = m;
       q = n;
       
       Normalise();
   }
}

//Constructor with 1 double parameter m
//Sets numerator to m*precision.(denominator = precision by default)
//Finally generates normalised form .
Fraction::Fraction(double d)
{
    p = d*precision();
    q = precision();
    Normalise();
}

//Destructor
//No need to destroy since only primitive data types are used in designing UDT
Fraction::~Fraction()
{}


//Copy Constructor takes a constant Fraction object and sets its numerator and denominator to caller object 
Fraction::Fraction(const Fraction & fr)
{
    p = fr.p;
    q = fr.q;
}

/* Copy Assignment Constructor takes a constant Fraction object and returns by value after setting 
numerator and denominator correctly and avoiding self assignment */
Fraction& Fraction::operator=(const Fraction & fr)
{
    if(this != &fr)
    {
        p = fr.p;
        q = fr.q;
    }
    return *this;
}

//Unary Plus - Returns a new fraction object by value created from the data members of the caller Fraction object
Fraction Fraction::operator+()
{
    Fraction nf(+p,q);
    return nf;
}

//Unary Minus - Returns a new fraction object by value created from the data members of the caller Fraction object
Fraction Fraction::operator-()
{
    Fraction nf(-p,q);
    return nf;
}

// Pre-Increment - increments fraction by 1( sets p <- p + q )
//Also normalises and returns the operated object through this pointer. 
Fraction& Fraction::operator++()
{
    p = p + q;
    Normalise();
    return *this;
}

//Post-Increment -first Copies the Fraction object which is to be operated, in nf (another variable)
//Now it operates on itself ( sets p <- p + q )
//returns nf 
Fraction Fraction::operator++(int)
{
    Fraction nf(p,q);
    p = p + q;
    Normalise();
    return nf;
}

// Post-Decrement - decrements fraction by 1( sets p <- p - q )
//Also it normalises and returns the operated object through this pointer. 
Fraction& Fraction::operator--()
{
    p = p - q;
    Normalise();
    return *this;
}

//Post-Decrement -first Copies the Fraction object which is to be operated, in nf (another variable)
//Now operates on itself ( sets p <- p - q ) and returns the copy previously stored by value
Fraction Fraction::operator--(int)
{
    Fraction nf(p,q);
    p = p - q;
    Normalise();
    return nf;
}

//Addition -Implemented using friend function.
//Takes two const objects as parameters and adds them using simple mathematical simplifications
//returns new Fraction object as the result of Addition
Fraction operator+(const Fraction& f1, const Fraction& f2)
{
    Fraction f3;
    f3.q = f3.lcm(f1.q,f2.q);
    f3.p = f1.p*(f3.q/f1.q)+f2.p*(f3.q/f2.q);
    f3.Normalise();
    return f3;
}


//Subtraction -Implemented using friend function.
//Takes two const objects as parameters and subtracts them using simple mathematical simplifications
//returns new Fraction object as the result of Subtraction
Fraction operator-(const Fraction& f1, const Fraction& f2)
{
    Fraction f3;
    f3.q = f3.lcm(f1.q,f2.q);
    f3.p = f1.p*(f3.q/f1.q)-f2.p*(f3.q/f2.q);
    f3.Normalise();
    return f3;
}


//Multiplication -Implemented using friend function.
//Takes two const objects as parameters and multiplies them using simple mathematical simplifications
//returns new Fraction object as the result of Multiplication
Fraction operator*(const Fraction& f1, const Fraction& f2)
{
    Fraction f3(f1.p*f2.p,f1.q*f2.q);
    return f3;
}


//Division -Implemented using friend function.
//Takes two const objects as parameters and divides them using simple mathematical simplifications
//returns new Fraction object as the result of Division
Fraction operator/(const Fraction& f1, const Fraction& f2)
{
    Fraction f3(f1.p*f2.q,f1.q*f2.p);
    return f3;
}


//Remainder -Implemented using friend function.
//Takes two const objects as parameters and calculates residue using simple mathematical simplifications
//returns new Fraction object as the result of Remainder
Fraction operator%(const Fraction& f1, const Fraction& f2)
{
    Fraction f3;
    f3.q = f3.lcm(f1.q,f2.q);
    f3.p = (f1.p*(f3.q/f1.q))%(f2.p*(f3.q/f2.q));
    f3.Normalise(); 
    return f3;
}

//Equality check using AND operation
bool Fraction::operator==(const Fraction& f)
{
    return p==f.p && q==f.q;
}

//Inequality check using OR operation
bool Fraction::operator!=(const Fraction& f)
{
    return p!=f.p || q!=f.q;
}

//Comparison after mathematical simplification
bool Fraction::operator<(const Fraction& f)
{
    return p*f.q < q*f.p;
}

//Comparison after mathematical simplification
bool Fraction::operator<=(const Fraction& f)
{
    return p*f.q <= q*f.p;
}

//Comparison after mathematical simplification
bool Fraction::operator>(const Fraction& f)
{
    return p*f.q > q*f.p;
}

//Comparison after mathematical simplification
bool Fraction::operator>=(const Fraction& f)
{
    return p*f.q >= q*f.p;
}

//Special operator of inversion of fractions. ( p/q -> q/p)
//Throws an exception if inversion causes denominator to be zero
//Otherwise returns a new fraction object after inversion.
Fraction Fraction::operator!()
{   
    try
    {
        if(p == 0)
        {
            throw " Exception: Inversion set denominator to 0";
        }

        Fraction nf(q,p);
        return nf;

    }
    catch(const char *msg)
    {
        cerr<<msg<<endl;
    }


}

//Static Constants of Fraction Class Implemented here:
const Fraction Fraction::sc_fUnity = Fraction();
const Fraction Fraction::sc_fZero = Fraction(0);
