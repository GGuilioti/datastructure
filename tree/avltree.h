#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    int height;
    Node* left;
    Node* right;
}Node;

typedef struct avltree
{
    Node* root;
}AvlTree;

AvlTree* initialize(AvlTree* a);

bool empty(AvlTree* a);

int height(Node* n);

int rebalance(Node* n);

Node* rightRotate(Node* n);

Node* leftRotate(Node* n);

Node* insert(Node* n);

Node* remove(Node* n, int value);