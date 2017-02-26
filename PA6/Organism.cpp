#include "Organism.h"
#include <iostream>

Organism::Organism(): step(0), x(0), y(0){
    
}

Organism::Organism(int _x, int _y):step(0), x(_x), y(_y){
    
}
Organism::Organism(int _x, int _y, int _step):step(_step), x(_x), y(_y){
    
}
Organism::~Organism(){
    step = 0;
    x = 0;
    y = 0;
}

void Organism::setX(int _x){
    x = _x;
}
void Organism::setY(int _y){
    y = _y;
}

int Organism::getX(){
    return x;
}
int Organism::getY(){
    return y;
}
