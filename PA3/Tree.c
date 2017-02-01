///////PA3//////ywang20/////YixueWang///
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Tree.h"

struct treeItem{
    char *word;
    int count;
    struct treeItem *leftChild, *rightChild, *parentNode;
    
};

typedef struct treeItem Node;

Node *root;

Node *findItem(Node *p, char *w) {
    if (p == NULL)
        return NULL; // item not found
    int c = strcmp(w, p->word);
    if (c == 0){
        return p;
    }
    else if(c < 0){
        return findItem(p->leftChild, w);
    }
    return findItem(p->rightChild, w);
}

Node *addItem(Node *p, char *w, Node *parent) {
    if (p == NULL){
        p = malloc(sizeof(Node));
        char *c = malloc(strlen(w)+1);
        p->word = strcpy(c, w);
        p->count = 1;
        p->leftChild = p->rightChild = NULL;
        p->parentNode = parent;
        return p;
    };
    int c = strcmp(w, p->word);
    if (c == 0){
        p->count++;
    }
    else if (c < 0){
         p->leftChild = addItem(p->leftChild, w, p);
    }
    else{
        p->rightChild = addItem(p->rightChild, w, p);
    }
    return p;
}

int main(){
    return 0 ;
}
