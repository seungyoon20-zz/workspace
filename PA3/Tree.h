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

#endif
