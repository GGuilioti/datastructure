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