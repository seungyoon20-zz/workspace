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
    void breed(int row, int col, Organism** B[]);
    void move(int row, int col, Organism** B[]);
    void print();
    
    int getStepAfterLastEating() const;
private:
    int stepAfterEat;
};
#endif
