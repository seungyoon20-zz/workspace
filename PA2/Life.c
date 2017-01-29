/////CS2303//C01//PA2///WangYixue//ywang20//
#include <stdio.h>
#include <stdlib.h>
#include "Life.h"


int **B, **C, **D;


int main(int argc, char *argv[]){
    FILE *input;
    int  x, y, gens, i;
    
    if(argc < 5){
        printf("Need 5 argcs!!!!\n");
        exit(-1);}
    
    
    
    x = atoi(argv[1]);
    y = atoi(argv[2]);
    gens = atoi(argv[3]);
    
    
    input = fopen(argv[4], "r");
    
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
        while(!feof(input)){
            
            
            if(c == 120){
                B[j][k] = 1;
            }
            
            if(c == 10){
                break;
            }
            
            k++;
            c = fgetc(input);
        }
    }
    
    for(int l = 0; l < 3* x; l++){
        for(int m = 0; m <3 * y; m++){
                printf("%d", B[l][m]);
        }
        printf("\n");
    }
    printf("\n");
    
    for(int l = 0; l < 3* x; l++){
        for(int m = 0; m <3 * y; m++){
            printf("%d", countNeighbor(3*x, 3*y, B, l, m));
        }
        printf("\n");
    }
    
    printf("\n");
    playOne(3*x, 3*y, C, B);
    
    for(int l = 0; l < 3 * x; l++){
        for(int m = 0; m < 3 * y; m++){
            printf("%d", C[l][m]);
        }
        printf("\n");
    }
    
    printf("%d\n", ifStop(3*x, 3*y, B, D, D));
    printf("%d\n", ifStop(3*x, 3*y, D, C, B));
    printf("%d\n", ifStop(3*x, 3*y, D, D, D));
    printf("%d\n", ifSame(3*x, 3*y, C, D));
    
    
    
    return 0;
}
