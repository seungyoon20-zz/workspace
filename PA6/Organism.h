#ifndef ORGANISM_H_
#define ORGANISM_H_
class Organism{
public:
    Organism();
    Organism(int _x, int _y);
    Organism(int _x, int _y, int _step);
    virtual ~Organism();
    
    //virtual void breed(int row, int col, Organism** B[]) = 0;
    //friend Organism*** move(int row, int col, Organism** B[]) = 0;
    virtual void print() = 0;
    void setX(int _x);
    void setY(int _y);
    int getX();
    int getY();
protected:
    int step;
    int x;
    int y;
};
#endif
