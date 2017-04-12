#include "Organism.h"
#include <iostream>

Organism::Organism(): step(0), x(0), y(0), ifNeedBehave(true){
    
}

Organism::Organism(int _x, int _y, bool _ifNeedBehave):step(0), x(_x), y(_y), ifNeedBehave(_ifNeedBehave){
    
}
Organism::Organism(int _x, int _y, int _step, bool _ifNeedBehave):step(_step), x(_x), y(_y), ifNeedBehave(_ifNeedBehave){
    
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

void Organism::addStep(){
	step += 1;
}

int Organism::getStep(){
	return step;
}

bool Organism::getStatus(){
	return ifNeedBehave;
}

int Organism::getStepAfterLastEating(){
	return 0;
}
Organism*** Organism::starvation(int g, Organism** B[]){
	return B;
}
