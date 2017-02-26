#ifndef ORGANISM_H_
#define ORGANISM_H_
class Organism{
public:
    Organism();
    Organism(int _x, int _y);
    virtual ~Organism();
    virtual void breed(int row, int col, Organism* B[]) = 0;
    virtual void move(int row, int col, Organism* B[]) = 0;
    virtual void print() = 0;
protected:
    int step;
    int x;
    int y;
};
#endif
