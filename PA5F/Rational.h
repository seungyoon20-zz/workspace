#ifndef RATIONAL_H_
#define RATIONAL_H_

#include <iostream>
using std::ostream;
using std::istream;
#include <cmath>
using std::abs;


class Rational{
    //REQUIRED OPERATOR OVERLOADING
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
    
    friend ostream& operator<<(ostream& a, Rational& b);
    friend istream& operator>>(istream& a, Rational& b);
    
    //EXTRA POINTS
    friend Rational& operator+=(Rational& a, Rational& b);
    friend Rational& operator-=(Rational& a, Rational& b);
    friend Rational& operator*=(Rational& a, Rational& b);
    friend Rational& operator/=(Rational& a, Rational& b);

    
    //EXTRA HELPER FRIEND FUNCTION
    friend int gcd(int a, int b);
    
    
public:
    //FOUR REQUARED CONSTRUCTOR & DESTRUCTOR
    Rational(const Rational& r);
    Rational(const int wholeNumber);
    Rational(const int num, const int denom);
    Rational();
    ~Rational();
    
    //EXTRA HELPER CONSTRUCTOR
    Rational(char n, const Rational& r);
    

    
    //EXTRA POINTS
    Rational& operator=(Rational b);
    char getName() const;
    
    //REQUIRED DOUBLE CONVERTION FUNCTION
    double getDouble();

private:
    int upper;
    int lower;
    char name;
    
    void simplify();
};
#endif
