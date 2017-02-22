#include <iostream>
#include "Expression.h"

Expression::Expression(): Rational(), name(0){
    
}

Expression::Expression(char n, int num, int denom): Rational(num, denom), name(n){
    
}

Expression::~Expression(){
    name = 0;
}
