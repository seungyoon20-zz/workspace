//////////PA3///////////ywang20/////////////////
#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"
#include "Input.h"
#include "Output.h"


int main(int argc, char *argv[]){
    FILE *output;
    FILE **input;
    Node *root = NULL;
    int d = 0;
    int t = 0;
    
    if(argc < 3){
        printf("Need at least ONE outputfile and ONE inputfile!!\n");
        exit(-1);
    }
    
    input =  malloc((argc - 2) * sizeof(FILE));
    int i = 0;
    while(i < argc - 2){
        input[i] =  fopen(argv[i+2], "r");
        if (!input[i]) {
            printf("Unable to open input file\n");
            exit(-1);
        }
        root = parseFile(input[i], root, NULL);
        fclose(input[i]);
        i++;
        //root = balanceNode(root);
    }
    
    int *distinct = malloc(sizeof(int));
    int *total = malloc(sizeof(int));
    
    *distinct = d;
    *total = t;
    
    output = fopen(argv[1], "w");

    output = printTree(root, output, distinct, total);
    fprintf(output, "---------------------------\n%10d %20s\n%10d %20s\n", *distinct, "Distinct words", *total, "Total");
    fprintf(stdout, "---------------------------\n%10d %20s\n%10d %20s\n", *distinct, "Distinct words", *total, "Total");
    fprintf(stdout, "Tree Height%d", getHeight(root));
    free(input);
    fclose(output);
    return 0;
}
