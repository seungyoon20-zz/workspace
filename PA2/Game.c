/////CS2303//C01//PA2///WangYixue//ywang20//
#include <stdio.h>
//#include "Board.h"
//#include "Game.h"
#include "Life.h"


int ifStop(int x, int y, int *Now[], int *Prev[], int *PPrev[]){
    int i, j;
    int result;
    
    int ifRepeatPrev = ifSame(x, y, Now, Prev);
    int ifRepeatPPrev = ifSame(x, y, Now, PPrev);
    
    int ifAnyAlive = 0;
    for(i = 0; i < x; i++){
        for(j = 0; j < y; j++){
            if(*(Now[i]+j) != 0){
                ifAnyAlive  = 1;
                break;
            }
        }
        if(ifAnyAlive == 1){
            break;
        }
    }
    
    result = !ifAnyAlive || ifRepeatPrev || ifRepeatPPrev;
    
    return result;
}

int countNeighbor(int x, int y, int *Board[], int _x, int _y){
    int num = 0;
    if(_x != 0 ){
        if(_y != 0){
            num += *(Board[_x - 1]+ _y - 1);
        }
        if(_y != y-1){
            num += *(Board[_x - 1]+ _y + 1);
        }
        num += *(Board[_x - 1]+ _y);
    }
    
    if(_x != x-1){
        if(_y != 0){
            num += *(Board[_x + 1]+ _y - 1);
        }
        if(_y != y-1){
            num += *(Board[_x + 1]+ _y + 1);
        }
        num += *(Board[_x + 1]+ _y);
            
    }
    
    if(_y != 0){
        num += *(Board[_x]+ _y - 1);
    }
    if(_y != y-1){
        num += *(Board[_x]+ _y + 1);
    }
    
    
    return num;
}

void playOne(int x, int y, int *New[], int *Old[]){
    int i, j;
    int neighbors;
    for(i = 0; i < x; i++){
        for(j = 0; j < y; j++){
            neighbors = countNeighbor(x, y, Old, i, j);
            if(neighbors == 3){
                *(New[i]+j) = 1;
                continue;
            }
            if((neighbors == 2) && (*(Old[i]+j) == 1)){
                *(New[i]+j) = 1;
                continue;
            }
            *(New[i]+j) = 0;
        }
    }
}
