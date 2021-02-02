#include<iostream>
#include<stdlib.h>  
using namespace std;

#include "Fraction.hxx"


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

void Fraction::Normalise()
{
    int g = gcd(p,q);
    p /= g;
    q /= g;

    if( p == 0 )
        q = 1;
    
} 

Fraction::Fraction()
{
    p = 1;
    q = 1;
}

Fraction::Fraction(int m)
{
    p = m;
    q = 1;
}

Fraction::Fraction(int m,int n)
{
   if(n==0)
   {
       cout<<"Cant create fraction with denominator of fraction = 0"<<endl;
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

Fraction::Fraction(double d)
{
    p = d*precision();
    q = precision();
    Normalise();
}

Fraction::~Fraction()
{}

Fraction::Fraction(const Fraction & fr)
{
    p = fr.p;
    q = fr.q;
}

Fraction& Fraction::operator=(const Fraction & fr)
{
    if(this != &fr)
    {
        p = fr.p;
        q = fr.q;
    }
    return *this;
}

Fraction Fraction::operator+()
{
    Fraction nf(+p,q);
    return nf;
}

Fraction Fraction::operator-()
{
    Fraction nf(-p,q);
    return nf;
}

Fraction Fraction::operator++()
{
    p = p + q;
    Normalise();
    return *this;
}

Fraction Fraction::operator++(int)
{
    Fraction nf(p,q);
    p = p + q;
    Normalise();
    return nf;
}

Fraction Fraction::operator--()
{
    p = p - q;
    Normalise();
    return *this;
}

Fraction Fraction::operator--(int)
{
    Fraction nf(p,q);
    p = p - q;
    Normalise();
    return nf;
}

Fraction operator+(const Fraction& f1, const Fraction& f2)
{
    Fraction f3;
    f3.q = f3.lcm(f1.q,f2.q);
    f3.p = f1.p*(f3.q/f1.q)+f2.p*(f3.q/f2.q);
    f3.Normalise();
    return f3;
}

Fraction operator-(const Fraction& f1, const Fraction& f2)
{
    Fraction f3;
    f3.q = f3.lcm(f1.q,f2.q);
    f3.p = f1.p*(f3.q/f1.q)-f2.p*(f3.q/f2.q);
    f3.Normalise();
    return f3;
}

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
    Fraction f3(f1.p*f2.p,f1.q*f2.q);
    return f3;
}

Fraction operator/(const Fraction& f1, const Fraction& f2)
{
    Fraction f3(f1.p*f2.q,f1.q*f2.p);
    return f3;
}

Fraction operator%(const Fraction& f1, const Fraction& f2)
{
    Fraction f3;
    f3.q = f3.lcm(f1.q,f2.q);
    f3.p = (f1.p*(f3.q/f1.q))%(f2.p*(f3.q/f2.q));
    f3.Normalise(); 
    return f3;
}

bool Fraction::operator==(const Fraction& f)
{
    return this->p==f.p && this->q==f.q;
}

bool Fraction::operator!=(const Fraction& f)
{
    return this->p!=f.p || this->q!=f.q;
}

bool Fraction::operator<(const Fraction& f)
{
    return this->p*f.q < this->q*f.p;
}

bool Fraction::operator<=(const Fraction& f)
{
    return this->p*f.q <= this->q*f.p;
}

bool Fraction::operator>(const Fraction& f)
{
    return this->p*f.q > this->q*f.p;
}

bool Fraction::operator>=(const Fraction& f)
{
    return this->p*f.q >= this->q*f.p;
}

Fraction Fraction::operator!()
{
    if(this->p == 0)
    {
        throw runtime_error("Inversion set denominator to 0");
    }

    Fraction nf(this->q,this->p);
    return nf;
}

const Fraction Fraction::sc_fUnity = Fraction();
const Fraction Fraction::sc_fZero = Fraction(0);
