/////CS2303//C01//PA2///WangYixue//ywang20//
#include <stdio.h>
#include "Life.h"


int ifStop(int x, int y, int *Now[], int *Prev[], int *PPrev[]){
    int i, j;
    int result;                                                     //overall result of the function
    
    int ifRepeatPrev = ifSame(x, y, Now, Prev);       //check if the board change since last generation
    int ifRepeatPPrev = ifSame(x, y, Now, PPrev);     //check if the board game goes to a recursion
    
    int ifAnyAlive = 0;                               //check if there is any cell alive on this board
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
}//ifStop



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
}//playOne
