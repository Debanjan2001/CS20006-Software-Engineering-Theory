#include<iostream>
#include<stdlib.h>  
using namespace std;

#include "Fraction.hpp"

int Fraction::precision()
{
    return 10000;
}

int Fraction::gcd(int a, int b)
{
    if(a%b == 0)
        return b;
    return gcd(b,a%b);
} 

int Fraction::lcm(int a ,int b)
{
    return (a*b)/gcd(a,b);
}

void Fraction::Normalise()
{
    int g = gcd(p,q);
    p /= g;
    q /= g;
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
       exit(1);
   }
   if(m==0)
   {
       p = 0;
       q = 1;
   }
   else if(n<0)
   {
       p = -m;
       q = -n;
   }
   else
   {
       p = m;
       q = n;
   }

}

Fraction::Fraction(double d)
{
    p = d*precision();
    q = precision();
}

Fraction::Fraction(const Fraction & fr)
{
    p = fr.p;
    q = fr.q;
}

Fraction& Fraction::operator=(const Fraction & fr)
{
    p = fr.p;
    q = fr.q;
    return *this;
}

Fraction operator+(const Fraction& f)
{
    Fraction nf(+f.p,f.q);
    return nf;
}

Fraction operator-(const Fraction& f)
{
     Fraction nf(-f.p,f.q);
    return nf;
}


Fraction& operator++(Fraction& f)
{
    f.p = f.p + f.q;
    return f;
}

Fraction operator++(Fraction& f,int)
{
    Fraction nf(f.p,f.q);
    f.p = f.p + f.q;
    return nf;
}

Fraction& operator--(Fraction& f)
{
    f.p = f.p - f.q;
    return f;
}

Fraction operator--(Fraction& f,int)
{
    Fraction nf(f.p,f.q);
    f.p = f.p - f.q;
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
    f3.Normalise();
    return f3;
}

Fraction operator/(const Fraction& f1, const Fraction& f2)
{
    Fraction f3(f1.p*f2.q,f1.q*f2.p);
    f3.Normalise();
    return f3;
}

Fraction operator%(const Fraction& f1, const Fraction& f2)
{
    //to be done
    Fraction f3(f1.p*f2.q,f1.q*f2.p);
    f3.Normalise();
    return f3;
}

bool operator==(const Fraction& f1, const Fraction& f2)
{
    //normalise
    return f1.p==f2.p && f1.q==f2.q;
}

bool operator!=(const Fraction& f1, const Fraction& f2)
{
    //normalise
    return f1.p!=f2.p || f1.q==f2.q;
}

bool operator<(const Fraction& f1, const Fraction& f2)
{
    //normalise
    return f1.p*f2.q < f1.q*f2.p;
}

bool operator<=(const Fraction& f1, const Fraction& f2)
{
    //normalise
    return f1.p*f2.q <= f1.q*f2.p;
}

bool operator>(const Fraction& f1, const Fraction& f2)
{
    //normalise
    return f1.p*f2.q > f1.q*f2.p;
}

bool operator>=(const Fraction& f1, const Fraction& f2)
{
    //normalise
    return f1.p*f2.q >= f1.q*f2.p;
}

Fraction operator!(const Fraction& fr)
{
    try
    {
        if(fr.p == 0)
        {
            throw fr.p;
        }

        Fraction nf(fr.q,fr.p);
        return nf;

    }
    catch(int x)
    {
        cout<<"Exception found! Inversion caused denominator to be zero"<<endl;
        Fraction nf(fr.q,fr.p);
        return nf;
    }
}

istream & operator>>(istream& in,Fraction& f)
{
    in>>f.p>>f.q;
    f.Normalise();
    return in;
}

ostream & operator<<(ostream& out,const Fraction& f)
{
    if(f.q == 1)
    {
        out<< f.p <<endl;
    }
    else
    {
        out<< f.p <<" / "<< f.q <<endl;
    }
    return out;
}

Fraction const Fraction::sc_fUnity = Fraction();
Fraction const Fraction::sc_fZero = Fraction(0);




Fraction::~Fraction()
{
    // delete &p;
    // delete &q;
}