#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum Color { RED, BLACK};

typedef struct node
{
    int data;
    int color;
    Node* left;
    Node* right;
}Node;

typedef struct redblacktree
{
    Node* root;
}RedBlackTree;

int cor(Node* c);

void changeColor(Node* n);

Node* leftRotate(Node* n);

Node* rightRotate(Node* n);

Node* moveLeftRed(Node* n);

Node* moveRightRed(Node* n);

Node* balance(Node* n);

int insert(RedBlackTree* rb, int value);

Node* insertNode(Node* n, int value, int *ret);

int remove(RedBlackTree* rb, int value);

Node* removeNode(Node* n, int value);

Node* removeMinimum(Node* n);

Node* minimum(Node* n);