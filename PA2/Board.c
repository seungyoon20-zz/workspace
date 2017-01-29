/////CS2303//C01//PA2///WangYixue//ywang20//
#include <stdio.h>
#include "Life.h"

int ifSame(int x, int y, int *ArrayA[], int *ArrayB[]){ //determine if 2 boards are totally the same
    int i, j;
    int result = 1;
    for (i = 0; i < x; i++){
        for (j = 0; j < y ; j++){
            result = (result && (*(ArrayA[i]+j) == *(ArrayB[i] +j )));
        }
    }
    return result;
}

void printBoard(int x, int y, int *Board[]){
    int i, j;
    
}
