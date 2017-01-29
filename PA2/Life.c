/////CS2303//C01//PA2///WangYixue//ywang20//
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <conio.h>
#include "Life.h"
int **B, **C, **D;
unsigned int x, y, gens;



int main(int argc, char *argv[]){
    
    FILE *input;
    int i;
    int print, pause;
    
    if(argc < 5){
        printf("Need 5 argcs!!!!\n");
        exit(-1);}
    
    
    
    x = atoi(argv[1]);
    y = atoi(argv[2]);
    gens = atoi(argv[3]);
    
    
    input = fopen(argv[4], "r");
    
    if (argc >= 6 && *argv[5] == 121){
        print = 1;
    }
    else{
        print = 0;
    }
    
    if (argc >= 7 && *argv[6] == 121){
        pause = 1;
    }
    else{
        pause = 0;
    }
    
    if(!input){
        printf("Unable to open file\n");
        exit(-1);}
    
    B = malloc(3 * x * sizeof(int *));
    C = malloc(3 * x * sizeof(int *));
    D = malloc(3 * x * sizeof(int *));
    
    if(B){
        for (i = 0; i < 3*x; i++){
        B[i] = malloc( 3*y * sizeof (int));
        if (!B[i]){
            exit(-1);}      /* error */
        }
    }
    if(C){
        for (i = 0; i < 3*x; i++){
            C[i] = malloc( 3*y * sizeof (int));
            if (!C[i]){
                exit(-1);}      /* error */
        }
    }
    if(D){
        for (i = 0; i < 3*x; i++){
            D[i] = malloc( 3*y * sizeof (int));
            if (!D[i]){
                exit(-1);}      /* error */
        }
    }
    
    
    for(int n = 0; n < 3*x; n++){
        for (int o = 0; o < 3*y; o++){
            B[n][o] = 0;
            C[n][o] = 0;
            D[n][o] = 0;
        }
    }

    
    
    int c;
    int k, j;
    
    for(j = x; j < 2*x; j++){
       c = fgetc(input);
       k = y;
        while(c != 10){
            
            
            if(c == 120){
                B[j][k] = 1;
            }
            
            if(feof(input)){
                break;
            }
            
            k++;
            c = fgetc(input);
        }
    }
    fclose(input);
    
    printBoard(3*x, 3*y, B);
    
    
    int gen = 0;
    while(gen < gens){
        if(kbhit() || pause == 0){
            
        
            if(gen % 3 == 0){
                playOne(3*x, 3*y, C, B);
                printBoard(3*x, 3*y, C);
                if(ifStop(3*x, 3*y, C, B, D)){
                    break;
                }
            }
            if(gen % 3 == 1){
                playOne(3*x, 3*y, D, C);
                printBoard(3*x, 3*y, D);
                if(ifStop(3*x, 3*y, D, C, B)){
                    break;
                }
            }
            if(gen % 3 ==2){
                playOne(3*x, 3*y, B, D);
                printBoard(3*x, 3*y, B);
                if(ifStop(3*x, 3*y, B, D, C)){
                    break;
                }
            }
            gen ++;
        
        }
    }
  
    
    
    return 0;
}
