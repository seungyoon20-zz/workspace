/////CS2303//C01//PA2///WangYixue//ywang20//

#ifndef LIFE_H_
#define LIFE_H_

int ifSame(int x, int y, int *ArrayA[], int *ArrayB[]); //board.c
void printBoard(int x, int y, int *Board[]);
int countNeighbor(int x, int y, int *Board[], int _x, int _y);


int ifStop(int x, int y, int *Now[], int *Prev[], int *PPrev[]); //game.c
void playOne(int x, int y, int *New[], int *Old[]);

#endif
