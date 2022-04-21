#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    Node* left;
    Node* right;
}Node;

typedef struct binarytree
{
    Node* root;
}BinaryTree;

BinaryTree* initialize(BinaryTree* b);

bool empty(BinaryTree* b);

int nodes(Node* n);

void copy(Node* n1, Node* n2);

void inOrder(Node* n);

void preOrder(Node* n);

void postOrder(Node* n);




