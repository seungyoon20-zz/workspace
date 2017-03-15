#ifndef ORGANISM_H_
#define ORGANISM_H_
class Organism{
public:
    Organism();
    Organism(int _x, int _y, bool _ifNeedBehave);
    Organism(int _x, int _y, int _step, bool _ifNeedBehave);
    virtual ~Organism();
    
    virtual Organism*** breed(int g, Organism** B[]) = 0;
    virtual Organism*** move(int g, Organism** B[]) = 0;
    virtual Organism*** starvation(int g, Organism** B[]);
    virtual void print() = 0;
    void setX(int _x);
    void setY(int _y);
    int getX();
    int getY();

    void addStep();
    int getStep();
    bool getStatus();
    
    virtual int getStepAfterLastEating();
    virtual bool isAnt() = 0;
protected:
    int step;
    int x;
    int y;
    bool ifNeedBehave;
};
#endif
