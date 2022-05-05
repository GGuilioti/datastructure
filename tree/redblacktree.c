#include "redblacktree.h"

int color(Node* c)
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

Node* leftRotate(Node* n)
{
    Node* n2 = n->right;
    n->right = n2->left;
    n2->left = n;
    n2->color = n->color;
    n->color = RED;
    
    return n2;
}

Node* rightRotate(Node* n)
{
    Node* n2 = n->left;
    n->left = n2->right;
    n2->right = n;
    n2->color = n->color;
    n->color = RED;

    return n2;
}