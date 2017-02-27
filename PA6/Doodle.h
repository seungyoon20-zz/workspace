#include "Organism.h"
#ifndef DOODLE_H_
#define DOODLE_H_
class Doodle: public Organism{
public:
    //constructor&destructor
    Doodle();
    Doodle(int _x, int _y);
    Doodle(int _x, int _y, int step);
    ~Doodle();
    
    
    //overriding
    Organism*** breed(int g, Organism** B[]);
    Organism*** move(int g, Organism** B[]);
    void print();
    
    int getStepAfterLastEating() const;
    bool isAnt();
private:
    int stepAfterEat;
};
#endif
