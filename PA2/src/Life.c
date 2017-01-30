/////CS2303//C01//PA2///WangYixue//ywang20//
#include <stdio.h>
#include <stdlib.h>
//#include <curses.h>
//#include <conio.h>
#include "Life.h"
int **B, **C, **D;
unsigned int x, y, gens, print, pause;
FILE *input;



int main(int argc, char *argv[]){
    
    if(argc < 5){
        printf("Need 5 argcs!!!!\n");
        exit(-1);}
    
    
    
    x = atoi(argv[1]);
    y = atoi(argv[2]);
    gens = atoi(argv[3]); //read arguments
    
    
    input = fopen(argv[4], "r");                     //open file
    
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
    
    B = malloc(3 * x * sizeof(int *));                          //allocate the rows of the board
    C = malloc(3 * x * sizeof(int *));
    D = malloc(3 * x * sizeof(int *));
    
    int i;
    if(B){                                      //allocate the colums
        for (i = 0; i < 3*x; i++){
        B[i] = malloc( 3*y * sizeof (int));
            /*After execution of this statement, the array starting from B+i gets its memory.
             Then jump to the next row with i++*/
        if (!B[i]){
            exit(-1);}      /* error */
        }
        /*Check if error*/
    }
    if(C){
        for (i = 0; i < 3*x; i++){
            C[i] = malloc( 3*y * sizeof (int));
            /*After execution of this statement, the array starting from C+i gets its memory.
             Then jump to the next row with i++*/
            if (!C[i]){
                exit(-1);}      /* error */
        }
    }
    if(D){
        for (i = 0; i < 3*x; i++){
            D[i] = malloc( 3*y * sizeof (int));
            /*After execution of this statement, the array starting from D+i gets its memory.
             Then jump to the next row with i++*/
            if (!D[i]){
                exit(-1);}      /* error */
        }
    }
                                                //the i indicates which row is under modifying
    
    for(int n = 0; n < 3*x; n++){
        for (int o = 0; o < 3*y; o++){
            B[n][o] = 0;
            C[n][o] = 0;
            D[n][o] = 0;
            /*After this execution, the value at [n][o] of all 3 boards are initialized to 0.
             Then o++ to jump to next column*/
        }
        //n++ to modify next row.
    }

    
    
    int c;      //declare c
    int k, j;
    
    for(j = x; j < 2*x; j++){
       c = fgetc(input);
        /*After this execution, c reads the next character in the input file*/
       k = y;                           //initialize k to the start position y
        while(c != 10){
            if(c == 120){
                B[j][k] = 1;
            }
            //if c equals "x", store 1 at the [j][k]
            if(feof(input)){            //if reaches the end of the file, break.
                break;
            }
            
            k++;
            c = fgetc(input);
            /*After such execution, c becomes the next character in the input file.
             The while loop keep reading and storing until c becomes a \n.*/
        }
    }
    
    fclose(input);                                          //close file
    
    printBoard(3*x, 3*y, B);                                                //print the initial board
    
    
    int gen = 0;                                                        //gen stores the current generation
    while(gen < gens){
        if(pause == 1){
            printf("Press ENTER to play next generation..\n");
        }
        if( pause == 0 || getchar()){
            if(gen % 3 == 0){
                playOne(3*x, 3*y, C, B);
                if(print == 1){
                    printBoard(3*x, 3*y, C);
                }
                
        
                if(ifStop(3*x, 3*y, C, B, D)|| gen == gens-1){
                    if(print == 0){
                        printBoard(3*x, 3*y, C);
                    }
                    break;
                }
            }
            if(gen % 3 == 1){
                playOne(3*x, 3*y, D, C);
                if(print == 1){
                    printBoard(3*x, 3*y, D);
                }
                if(ifStop(3*x, 3*y, D, C, B)|| gen == gens-1){
                    if(print == 0){
                        printBoard(3*x, 3*y, D);
                    }
                    break;
                }
            }
            if(gen % 3 ==2){
                playOne(3*x, 3*y, B, D);
                if(print == 1){
                    printBoard(3*x, 3*y, B);
                }
                if(ifStop(3*x, 3*y, B, D, C) || gen == gens-1){
                    if(print == 0){
                        printBoard(3*x, 3*y, B);
                    }
                    break;
                }
            }
            gen ++;
            /*After those executions, the program finish updating the game boards, printing game board needed and determining if need to end the game(if need the loop get broken).
             And gen updates to go to the next generation for gen < gens.*/
        }
    }
    free(B);                                                        //free the memory of 3 game boards
    free(C);
    free(D);
    
    
    return 0;
}
