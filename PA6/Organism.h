#ifndef ORGANISM_H_
#define ORGANISM_H_
class Organism{
public:
    Organism();
    Organism(int _x, int _y);
    Organism(int _x, int _y, int _step);
    virtual ~Organism();
    
    virtual Organism*** breed(int g, Organism** B[]) = 0;
    virtual Organism*** move(int g, Organism** B[]) = 0;
    virtual void print() = 0;
    void setX(int _x);
    void setY(int _y);
    int getX();
    int getY();

    void addStep();
    int getStep();
    
    virtual bool isAnt() = 0;
protected:
    int step;
    int x;
    int y;
};
#endif
