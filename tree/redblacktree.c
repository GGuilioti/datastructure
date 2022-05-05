#include "redblacktree.h"

int cor(Node* c)
{
    if(c == NULL)
        return BLACK;
    else
        return c->color;
}

void changeColor(Node* n)
{
    n->color = !n->color;
    if (n->left != NULL)
        n->left->color = !n->left->color;
    if(n->right != NULL)
        n->right->color = !n->right->color;
}