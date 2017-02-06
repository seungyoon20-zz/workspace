///PA#///WangYixue//ywang20//

#ifndef TREE_H_
#define TREE_H_

struct treeItem{
    char *word;
    int count;
    struct treeItem *leftChild, *rightChild, *parentNode;
    
};

typedef struct treeItem Node;

Node *findItem(Node *p, char *w);
Node *addItem(Node *p, char *w, Node *parent);
int getHeight(Node *p);
int getBalanceFactor( Node *p );
Node *rotateLeftleft( Node *p);
Node *rotateLeftright(Node *p);
Node *rotateRightleft(Node *p);
Node *rotateRightright( Node *p);
Node *balanceNode( Node *p );


#endif
