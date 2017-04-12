/*
=======================================================================================================
Name		: Tree.c
Author		: Yixue Wang, Mingquan Liu
Version		: 1.1
Copyright	:
Description	: Balance the tree and add item to the tree.
=======================================================================================================
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Tree.h"


int getHeight(Node *p) {
    int height_left = 0;
    int height_right = 0;
    
    if( p->leftChild ){
        height_left = getHeight( p->leftChild );
    }
    if( p->rightChild ){
        height_right = getHeight( p->rightChild );
    }
    
    return height_right > height_left ? ++height_right : ++height_left;
}//getHeight

int getBalanceFactor( Node *p ) {
    int bf = 0;
    
    if( p->leftChild  ) bf += getHeight( p->leftChild );
    if( p->rightChild ) bf -= getHeight( p->rightChild );
    
    return bf ;
}//getBalanceFactor

Node *rotateLeftleft( Node *p) {
    Node *a = p;
    Node *b = a->leftChild;
    
    a->leftChild = b->rightChild;
    b->rightChild = a;
    b->parentNode = a->parentNode;
    a->parentNode = b;
    
    return( b );
}//rotateLeftleft

Node *rotateLeftright(Node *p) {
    Node *a = p;
    Node *b = a->leftChild;
    Node *e = b->rightChild;
    
    a->leftChild = e->rightChild;
    b->rightChild = e->leftChild;
    e->leftChild = b;
    e->rightChild = a;
    
    e->parentNode = a->parentNode;
    a->parentNode = e;
    b->parentNode = e;
    
    return( e );
}//rotateLeftright

Node *rotateRightleft(Node *p) {
    Node *a = p;
    Node *b = a->rightChild;
    Node *e = b->leftChild;
    
    a->rightChild = e->leftChild;
    b->leftChild = e->rightChild;
    e->rightChild = b;
    e->leftChild = a;
    
    e->parentNode = a->parentNode;
    a->parentNode = e;
    b->parentNode = e;
    
    return( e );
}//rotateRightleft

Node *rotateRightright( Node *p) {
    Node *a = p;
    Node *b = a->rightChild;
    
    a->rightChild = b->leftChild;
    b->leftChild = a;
    
    b->parentNode = a->parentNode;
    a->parentNode = b;
    
    return( b );
}//rotateRightright

Node *balanceNode( Node *p ) {
    //Node *newroot = NULL;
    if(p){
        /* Balance its children, if they exist. */
        if(p->leftChild){
            p->leftChild  = balanceNode(p->leftChild);
        }
        
        if(p->rightChild){
            p->rightChild = balanceNode(p->rightChild);
        }
        
        int bf = getBalanceFactor( p );
        
        if( bf >= 2 ) {
            /* Left Heavy */
            
            if( getBalanceFactor( p->leftChild ) <= -1 )
                return rotateLeftright(p);
            else
                return rotateLeftleft(p);
            
        }
        else if( bf <= -2 ) {
            /* Right Heavy */
            
            if( getBalanceFactor( p->rightChild ) >= 1 )
                return rotateRightleft(p);
            else
                return rotateRightright(p);
            
        }
    }
        return p;
}


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

Node *addItem(Node *p, char *w, Node *parent) {              //Add the word into the tree.
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
    
    return balanceNode(p);                              //Return the balanced node after adding
    //return p;
}
