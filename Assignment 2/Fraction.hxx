#ifndef FRACTION_HXX
#define FRACTION_HXX
#include<iostream>
#include<stdlib.h>
using namespace std;

class Fraction
{
    private:
        int p;
        unsigned int q;

        void Normalise();
        inline static int precision();
        inline static int gcd(int ,int);
        inline static int lcm(int, int);

    public:

        Fraction();
        Fraction(int);
        Fraction(int, int);
        Fraction(double);
        
        Fraction(const Fraction &);
        Fraction& operator=(const Fraction &);

        Fraction operator-();
        Fraction operator+();
        Fraction& operator++();
        Fraction operator++(int);
        Fraction& operator--();
        Fraction operator--(int);

        friend Fraction operator+(const Fraction&,const Fraction&);
        friend Fraction operator-(const Fraction&,const Fraction&);
        friend Fraction operator*(const Fraction&,const Fraction&);
        friend Fraction operator/(const Fraction&,const Fraction&);
        friend Fraction operator%(const Fraction&,const Fraction&);
        
        bool operator==(const Fraction&);
        bool operator!=(const Fraction&);
        bool operator<(const Fraction&);
        bool operator<=(const Fraction&);
        bool operator>(const Fraction&);
        bool operator>=(const Fraction&);

        Fraction operator!();
        
        friend inline istream & operator>>(istream &,Fraction&);
        friend inline ostream & operator<<(ostream &,const Fraction&);

        static const Fraction sc_fUnity;
        static const Fraction sc_fZero;

        ~Fraction();
};

inline int Fraction::precision()
{
    return 100000;
}

inline int Fraction::gcd(int a, int b)
{
    a = abs(a),b = abs(b);
    if(a%b == 0)
        return b;
    return gcd(b,a%b);
} 

inline int Fraction::lcm(int a ,int b)
{
    return abs((a*b)/gcd(a,b));
}


inline istream & operator>>(istream& in,Fraction& f)
{
    in>>f.p>>f.q;
    f.Normalise();
    return in;
}

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