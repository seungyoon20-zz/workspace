#include "Organism.h"
#ifndef ANT_H_
#define ANT_H_
class Ant : public Organism{
public:
    Ant();
    Ant(int _x, int _y, bool _ifNeedBehave);
    Ant(int _x, int _y, int _step, bool _ifNeedBehave);
    //Ant(const Ant& a);
    ~Ant();
    
    
    //overriding
    Organism*** breed(int g, Organism** B[]);
    Organism*** move( int g, Organism** B[]);
    void print();
    bool isAnt();

};
#endif
