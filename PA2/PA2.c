#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]){
    FILE *input;
    int k, x, y, gens;
    int *B[  ];
    
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
    
    //int *B[ ];
    unsigned int i, j, k;
    B = malloc(x * sizeof(int *));
    if (B){
        for (i = 0; i < x; i++) {
        B[i] = malloc(y * sizeof (int));
        if (!B[i]) {exit(-1);}
        }
    }
    
    printf("succeed!\n");
    return 0;
}
