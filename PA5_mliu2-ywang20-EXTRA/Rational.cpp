#include <cstdlib>
#include "Rational.h"
using namespace std;


//4REQUIRED CONSTUCTOR& DESTRUCTOR
Rational::Rational(const Rational& r): upper(r.upper), lower(r.lower), name(r.name){
    
}
Rational::Rational(const int wholeNumber): upper(wholeNumber), lower(1), name(0){
    
}

Rational::Rational(const int num, const int denom): upper(num), lower(denom), name(0){
    if(lower == 0){
        std::cout << "Denominator can not be 0!!"<<std::endl;
        exit(-1);
    }
}

Rational::Rational(): upper(0), lower(1), name(0){
    
}
Rational::~Rational(){
    lower = 0;
    upper = 0;
    name = 0;
}

//ADDITIONAL HELPER CONSTRUCTOR
Rational::Rational(char n, const Rational& r): upper(r.upper), lower(r.lower), name(n){
    this->simplify();
}



char Rational::getName() const{
    return name;
}



//REQUIRED DOUBLE CONVERTION FUNCTION
double Rational::getDouble(){
    return (double)upper/(double)lower;
}
//+ - * / > >= < <= == !=
//===========================================================
Rational operator+(Rational& a, Rational& b){
    Rational result(a.upper*b.lower+ a.lower*b.upper, a.lower*b.lower);
    result.simplify();
    return result;
}
Rational operator-(Rational& a, Rational& b){
    Rational result(a.upper*b.lower- a.lower*b.upper, a.lower*b.lower);
    result.simplify();
    return result;
}
Rational operator*(Rational& a, Rational& b){
    Rational result(a.upper*b.upper, a.lower*b.lower);
    result.simplify();
    return result;
}
Rational operator/(Rational& a, Rational& b){
    Rational result(a.upper*b.lower, a.lower*b.upper);
    result.simplify();
    return result;
}

bool operator==(Rational& a, Rational& b){
    return a.upper*b.lower == a.lower*b.upper;
}
bool operator!=(Rational& a, Rational& b){
    return a.upper*b.lower != a.lower*b.upper;
}
bool operator>(Rational& a, Rational& b){
    a.simplify();
    b.simplify();
    return a.upper*b.lower > a.lower*b.upper;
}
bool operator>=(Rational& a, Rational& b){
    a.simplify();
    b.simplify();
    return a.upper*b.lower >= a.lower*b.upper;
}
bool operator<(Rational& a, Rational& b){
    a.simplify();
    b.simplify();
    return a.upper*b.lower < a.lower*b.upper;
}
bool operator<=(Rational& a, Rational& b){
    a.simplify();
    b.simplify();
    return a.upper*b.lower <= a.lower*b.upper;
}

// << & >>
//=========================================================================
ostream& operator<<(ostream& a, Rational& b){
    if(b.lower == 1){
        a << b.upper;
    }
    else{
        a<< b.upper << "/" << b.lower;
    }
    return a;
}

istream& operator>>(istream& a, Rational& b){
    char useless;
    a >> b.upper;
    if(a.fail()){
    	   return a;
    }
    else
    {
        a.get(useless);
        if(useless == ' '){
            b.lower = 1;
        }
        else {
            a >> b.lower;
        }
        return a;
    }
    
}

//EXTRA POINTS
//=========================================================================
Rational& operator+=(Rational& a, Rational& b){
    a.upper = a.upper*b.lower+ a.lower*b.upper;
    a.lower = a.lower*b.lower;
    a.simplify();
    return a;
}
Rational& operator-=(Rational& a, Rational& b){
    a.upper = a.upper*b.lower- a.lower*b.upper;
    a.lower = a.lower*b.lower;
    a.simplify();
    return a;
}
Rational& operator*=(Rational& a, Rational& b){
    a.upper = a.upper*b.upper;
    a.lower = a.lower*b.lower;
    a.simplify();
    return a;
}
Rational& operator/=(Rational& a, Rational& b){
    a.upper = a.upper*b.lower;
    a.lower = a.lower*b.upper;
    a.simplify();
    return a;
}
Rational& Rational::operator=(Rational b){
    upper = b.upper;
    lower = b.lower;

    if(!name){
        name = b.name;
    }
    
    this->simplify();
    return *this;
}



//=========================================================================
int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a%b);
}

//=========================================================================
void Rational::simplify(){
    if(lower  < 0){
        lower = -lower;
        upper = -upper;
    }
    int g = gcd(abs(upper), abs(lower));
    upper = upper / g;
    lower = lower / g;
}
//=========================================================================
