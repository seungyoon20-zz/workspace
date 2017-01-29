/////CS2303//C01//PA2///WangYixue//ywang20//

#ifndef LIFE_H_
#define LIFE_H_

int ifSame(int x, int y, int *ArrayA[], int *ArrayB[]); //board.c


int ifStop(int x, int y, int *Now[], int *Prev[], int *PPrev[]); //game.c
int countNeighbor(int x, int y, int *Board[], int _x, int _y);
void playOne();

#endif
