/*
=======================================================================================================
Name		: PA3.c
Author		: Yixue Wang, Mingquan Liu
Version		: 1.1
Copyright	:
Description	: Runs the whole PA3 project
=======================================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"
#include "Input.h"
#include "Output.h"
//#include <time.h>

//FILE* timeOutput;


int main(int argc, char *argv[]){
    FILE *output;
    FILE **input;
    Node *root = NULL;
    int d = 0;
    int t = 0;
    
    //timeOutput = fopen("timecostFindElephantNonAVL-Kennedy+Obama.txt", "w");
    
    if(argc < 3){														//Check the if it is the desired input
        printf("Need at least ONE outputfile and ONE inputfile!!\n");
        exit(-1);
    }
    
    input =  malloc((argc - 2) * sizeof(FILE));
    int i = 0;
    while(i < argc - 2){                                                // Start reading the input file
        input[i] =  fopen(argv[i+2], "r");
        if (!input[i]) {
            printf("Unable to open input file\n");
            exit(-1);
        }
        root = parseFile(input[i], root, NULL);
        fclose(input[i]);										      // Closing the file when not using it.
        i++;
        
    }
    
    int *distinct = malloc(sizeof(int));
    int *total = malloc(sizeof(int));

    *distinct = d;
    *total = t;
    
    output = fopen(argv[1], "w");

    output = printTree(root, output, distinct, total);
    fprintf(output, "---------------------------\n%10d    %s\n%10d    %s\n", *distinct, "Distinct words", *total, "Total");
    fprintf(stdout, "---------------------------\n%10d    %s\n%10d    %s\n", *distinct, "Distinct words", *total, "Total");
    free(input);
    fclose(output);
    return 0;
}
