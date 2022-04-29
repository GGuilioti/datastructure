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

int bigger(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}