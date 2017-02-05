//////////PA3///////////ywang20/////////////////
#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"
#include "Output.h"


FILE* printTree(Node *p, FILE *file_A, int *distinct, int *total){
    if(p && p->leftChild){
        printTree(p->leftChild, file_A, distinct, total);
    }
    if(p){
        fprintf(file_A, "%10d %20s\n", p->count, p->word);
        fprintf(stdout, "%10d %20s\n", p->count, p->word);
        *distinct += 1;
        *total += p->count;
    }
    if(p && p->rightChild){
        printTree(p->rightChild, file_A, distinct, total);
    }
    
    
    return file_A;
}
