/////CS2303//C01//PA2///WangYixue//ywang20//
#include <stdio.h>
#include "Life.h"

int ifSame(int x, int y, int *ArrayA[], int *ArrayB[]){ //determine if 2 boards are totally the same
    int i, j;
    int result = 1;
    for (i = 0; i < x; i++){
        for (j = 0; j < y ; j++){
            result = (result && (*(ArrayA[i]+j) == *(ArrayB[i] +j )));
            /*After excution of this statement, the overall result modified by the new comparement result at position of [i][j]. The overall result was initialized as True at the very begining. If any of the comparement returns a False, the overall result will become false.
             After modifying [i][j], j++ jump to the next column.*/
        }
        /*After looping through the entire row, i++ to jump to the next row.*/
    }
    return result;
}//ifSame

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
}//countNeighbor

void printBoard(int x, int y, int *Board[]){
    int i, j;
    for(i = 0; i < x; i++){
        for(j = 0; j <y; j++){
            if(*(Board[i]+j) == 1){
                printf("X");
            }
            else{
                printf(" ");
            }
            /*After the excution of this statement, the program prints "X"/" " representing 1/0. j++ to jump to the next column*/
        }
        printf("\n");
        /*This statement helps start a new line. Then i++ to jump to the next row.*/
    }
    printf("\n");
}//printBoard
