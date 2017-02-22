
#include "Rational.h"
//using std::ostream;

Rational::Rational(const Rational& r): upper(r.upper), lower(r.lower){
    
}
Rational::Rational(const int wholeNumber): upper(wholeNumber), lower(1){
    
}

Rational::Rational(const int num, const int denom): upper(num), lower(denom){
    if(lower == 0){
        std::cout << "Denominator can not be 0!!"<<std::endl;
        exit(-1);
    }
}

Rational::Rational(): upper(0), lower(1){
    
}

Rational::~Rational(){
    lower = 0;
    upper = 0;
}

int Rational::getNuminator() const{
    return upper;
}
int Rational::getDenominator() const{
    return lower;
}
//===========================================================
Rational operator+(Rational& a, Rational& b){
//    a.upper = a.upper*b.lower- a.lower*b.upper;
//    a.lower = a.lower*b.lower;
//    return simplify(a);
    Rational result(a.upper*b.lower+ a.lower*b.upper, a.lower*b.lower);
    result.simplify();
    return result;
}
Rational operator-(Rational& a, Rational& b){
//    a.upper = a.upper*b.lower- a.lower*b.upper;
//    a.lower = a.lower*b.lower;
//    return simplify(a);
    Rational result(a.upper*b.lower- a.lower*b.upper, a.lower*b.lower);
    result.simplify();
    return result;
}
Rational operator*(Rational& a, Rational& b){
//    a.upper = a.upper*b.upper;
//    a.lower = a.lower*b.lower;
//    return simplify(a);
    Rational result(a.upper*b.upper, a.lower*b.lower);
    result.simplify();
    return result;
}
Rational operator/(Rational& a, Rational& b){
//    a.upper = a.upper*b.lower;
//    a.lower = a.lower*b.upper;
//    return simplify(a);
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
    return a.upper*b.lower > a.lower*b.upper;
}
bool operator>=(Rational& a, Rational& b){
    return a.upper*b.lower >= a.lower*b.upper;
}
bool operator<(Rational& a, Rational& b){
    return a.upper*b.lower < a.lower*b.upper;
}
bool operator<=(Rational& a, Rational& b){
    return a.upper*b.lower <= a.lower*b.upper;
}
//=========================================================================
Rational& operator+=(Rational& a, Rational& b){
    a.upper = a.upper*b.lower+ a.lower*b.upper;
    a.lower = a.lower*b.lower;
    a.simplify();
    return a;
//    Rational result(a.upper*b.lower+ a.lower*b.upper, a.lower*b.lower);
//    return simplify(result);
}
Rational& operator-=(Rational& a, Rational& b){
    a.upper = a.upper*b.lower- a.lower*b.upper;
    a.lower = a.lower*b.lower;
    a.simplify();
    return a;
//    Rational result(a.upper*b.lower- a.lower*b.upper, a.lower*b.lower);
//    return simplify(result);
}
Rational& operator*=(Rational& a, Rational& b){
    a.upper = a.upper*b.upper;
    a.lower = a.lower*b.lower;
    a.simplify();
    return a;
//    Rational result(a.upper*b.upper, a.lower*b.lower);
//    return simplify(result);
}
Rational& operator/=(Rational& a, Rational& b){
    a.upper = a.upper*b.lower;
    a.lower = a.lower*b.upper;
    a.simplify();
    return a;
//    Rational result(a.upper*b.lower, a.lower*b.upper);
//    return simplify(result);
}
Rational& Rational::operator=(Rational b){
    upper = b.upper;
    lower = b.lower;
    return *this;
}

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
    a.get(useless);
    if(useless == ' '){
        b.lower = 1;
    }
    else {
        a >> b.lower;
    }
    return a;
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
