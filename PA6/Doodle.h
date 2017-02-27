#include "Organism.h"
#ifndef DOODLE_H_
#define DOODLE_H_
class Doodle: public Organism{
public:
    //constructor&destructor
    Doodle();
    Doodle(int _x, int _y);
    ~Doodle();
    
    
    //overriding
    Organism*** breed(int g, Organism** B[]);
    Organism*** move(int g, Organism** B[]);
    void print();
    
    int getStepAfterLastEating() const;
private:
    int stepAfterEat;
};
#endif
