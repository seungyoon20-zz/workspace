#include "Doodle.h"
#include <iostream>

Doodle::Doodle(): Organism(), stepAfterEat(0){
    
}
Doodle::Doodle(int _x, int _y): Organism(_x, _y), stepAfterEat(0){
    
}
Doodle::~Doodle(){
    step = 0;
    x = 0;
    y = 0;
    stepAfterEat = 0;
}


//overriding
void Doodle::breed(int g, Organism** B[]){
    
}
Organism*** move(Organism* a,int row, int col, Organism** B[]){
    return 0;
}
void Doodle::print(){
    std::cout << "X";
}

int Doodle::getStepAfterLastEating() const{
    return stepAfterEat;
}
