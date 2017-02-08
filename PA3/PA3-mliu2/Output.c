/*
=======================================================================================================
Name		: Output.c
Author		: Yixue Wang, Mingquan Liu
Version		: 1.1
Copyright	:
Description	: Print out the desired output in specific file
=======================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"
#include "Output.h"


FILE* printTree(Node *p, FILE *file_A, int *distinct, int *total){
    if(p && p->leftChild){
        printTree(p->leftChild, file_A, distinct, total);
    }
    if(p){
        fprintf(file_A, "%10d    %s\n", p->count, p->word);                 //Print the tree following the alphabetic order
        fprintf(stdout, "%10d    %s\n", p->count, p->word);
        *distinct += 1;
        *total += p->count;
    }
    if(p && p->rightChild){
        printTree(p->rightChild, file_A, distinct, total);
    }
    
    
    return file_A;
}
