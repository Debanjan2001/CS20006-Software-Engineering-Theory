#ifndef FRACTION_HPP
#define FRACTION_HPP
#include<iostream>
using namespace std;

class Fraction
{
    private:
        int p;
        unsigned int q;

        void Normalise();
        static int precision();
        static int gcd(int ,int);
        static int lcm(int, int);

    public:

        Fraction();
        Fraction(int);
        Fraction(int, int);
        Fraction(double);
        
        Fraction(const Fraction &);
        Fraction& operator=(const Fraction &);

        friend Fraction operator-(const Fraction&);
        friend Fraction operator+(const Fraction&);
        friend Fraction& operator++(Fraction &); //pre
        friend Fraction operator++(Fraction &,int); //post
        friend Fraction& operator--(Fraction &);
        friend Fraction operator--(Fraction &,int);

        friend Fraction operator+(const Fraction&,const Fraction&);
        friend Fraction operator-(const Fraction&,const Fraction&);
        friend Fraction operator*(const Fraction&,const Fraction&);
        friend Fraction operator/(const Fraction&,const Fraction&);
        friend Fraction operator%(const Fraction&,const Fraction&);
        
        friend bool operator==(const Fraction&,const Fraction&);
        friend bool operator!=(const Fraction&,const Fraction&);
        friend bool operator<(const Fraction&,const Fraction&);
        friend bool operator<=(const Fraction&,const Fraction&);
        friend bool operator>(const Fraction&,const Fraction&);
        friend bool operator>=(const Fraction&,const Fraction&);

        friend Fraction operator!(const Fraction&);
        
        friend istream & operator>>(istream &,Fraction&);
        friend ostream & operator<<(ostream &,const Fraction&);

        static Fraction const sc_fUnity;
        static Fraction const sc_fZero;

        ~Fraction();
};

#endif