#include "Ant.h"
#include <iostream>

Ant::Ant(): Organism(){
    
}
Ant::Ant(int _x, int _y): Organism(_x, _y){
    
}
Ant::~Ant(){
    step = 0;
    x = 0;
    y = 0;
}


//overriding
void Ant::breed(int row, int col, Organism** B[]){
    
}
void Ant::move(int row, int col, Organism** B[]){
    
}
void Ant::print(){
    std::cout << "O";
}
