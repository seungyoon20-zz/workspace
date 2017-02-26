#include "Organism.h"
#include <iostream>

Organism::Organism(): step(0), x(0), y(0){
    
}

Organism::Organism(int _x, int _y):step(0), x(_x), y(_y){
    
}

Organism::~Organism(){
    step = 0;
    x = 0;
    y = 0;
}
