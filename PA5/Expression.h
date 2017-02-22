#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include "Rational.h"

class Expression: public Rational{
private:
    char name;
public:
    Expression();
    Expression(char n, int num, int denom);
    ~Expression();
};
#endif
