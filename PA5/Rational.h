#ifndef RATIONAL_H_
#define RATIONAL_H_

#include <iostream>
using std::ostream;
using std::istream;
#include <cmath>
using std::abs;


class Rational{
    friend Rational operator+(Rational& a, Rational& b);
    friend Rational operator-(Rational& a, Rational& b);
    friend Rational operator*(Rational& a, Rational& b);
    friend Rational operator/(Rational& a, Rational& b);
    friend bool operator==(Rational& a, Rational& b);
    friend bool operator!=(Rational& a, Rational& b);
    friend bool operator>(Rational& a, Rational& b);
    friend bool operator>=(Rational& a, Rational& b);
    friend bool operator<(Rational& a, Rational& b);
    friend bool operator<=(Rational& a, Rational& b);

    
    friend Rational& operator+=(Rational& a, Rational& b);
    friend Rational& operator-=(Rational& a, Rational& b);
    friend Rational& operator*=(Rational& a, Rational& b);
    friend Rational& operator/=(Rational& a, Rational& b);
    
    friend ostream& operator<<(ostream& a, Rational& b);
    friend istream& operator>>(istream& a, Rational& b);
    
    
    friend int gcd(int a, int b);
public:
    Rational(const Rational& r);
    Rational(const int wholeNumber);
    Rational(const int num, const int denom);
    Rational();
    ~Rational();
    
    Rational& operator=(Rational b);

    
    int getNuminator() const;
    int getDenominator()const;

private:
    void simplify();
protected:
    int upper;
    int lower;

    
};
#endif
