#include "Organism.h"
#include "Ant.h"
#include "Doodle.h"
#include <iostream>

Organism*** Board;
Doodle* Doodles;
Ant* Ants;
bool ifPause;
int seed;
int totalSteps;
int numOfDoodles;
int numOfAnts;
int grid;

int main(int argc, char* argv[]){
    Board = new Organism**[1];
    Board[0] = new Organism*[1];
    Board[0][0] = new Doodle(1, 2);
    Board[0][0] -> print();
//    Doodle b = Doodle(1, 2);
//    b.print();
    return 0;
}
