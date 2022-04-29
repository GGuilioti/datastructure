#include "avltree.h"

AvlTree* initialize(AvlTree* a)
{
    a->root = NULL;
}

bool empty(AvlTree* a)
{
    if(a->root == NULL)
        return true;
    else
        return false;
}

int height(Node* n)
{
    if(n == NULL)
        return -1;
    else
        return n->height;
}

int rebalance(Node* n)
{
    if(n == NULL)
        return -1;
    else
        return height(n->left) - height(n->right);
}

Node* rightRotate(Node* n)
{
    Node* aux = n->left;
    n->left = aux->right;
    aux->right = n;

    n->height = max(height(n->left), height(n->right)) +1;

    aux->height = max(height(aux->left), height(n->height)) +1;

    return aux;
}

Node* leftRotate(Node* n)
{
    Node* aux = n->right;
    n->right = aux->left;
    aux->left = n;

    aux->height = max(height(n->left), height(n->right)) +1;

    n->height = max(height(aux->right), height(n->height)) +1;

    return aux;
}