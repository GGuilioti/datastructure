#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    Node* left;
    Node* right;
}Node;

typedef struct binarysearchtree
{
    Node* root;
}BinarySearchTree;

BinarySearchTree* initialize(BinarySearchTree* b);

bool empty(BinarySearchTree* b);

int nodes(Node* n);

void copy(Node* n1, Node* n2);

void inOrder(Node* n);

Node* minimumIterative(Node* n);

Node* minimumRecursive(Node* n);

Node* maximumIterative(Node* n);

Node* maximumRecursive(Node* n);

Node* searchItarative(Node* n, int value);

Node* searchRecursive(Node* n, int value);

void insert(Node* n, int value);

int remove(Node* n, int value);