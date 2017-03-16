#include "Organism.h"
#ifndef DOODLE_H_
#define DOODLE_H_
class Doodle: public Organism{
public:
    //constructor&destructor
    Doodle();
    Doodle(int _x, int _y, bool _ifNeedBehave);
    Doodle(int _x, int _y, int _step, bool _ifNeedBehave);
    Doodle(int _x, int _y, int _step,  bool _ifNeedBehave, int _stepAfterEat);
    ~Doodle();
    
    
    //overriding
    Organism*** breed(int g, Organism** B[]);
    Organism*** move(int g, Organism** B[]);
    Organism*** starvation(int g, Organism** B[]);
    void print();
    
    int getStepAfterLastEating();
    bool isAnt();
private:
    int stepAfterEat;
};
#endif
