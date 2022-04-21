#include "binarytree.h"

BinaryTree* initialize(BinaryTree* b)
{
    b->root = NULL;
}

bool empty(BinaryTree* b)
{
    if(b->root == NULL)
        return true;
    else
        return false;
}

int nodes(Node* n)
{
    if(n == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + nodes(n->left) + nodes(n->right);
    }
}

void copy(Node* n1, Node* n2)
{
    if(n1 == NULL)
        n2 = NULL;
    else
    {
        n2 = malloc(sizeof(Node));
        n2->data = n1->data;
        copy(n1->left, n2->left);
        copy(n1->right, n2->right);
    }
}

void inOrder(Node* n)
{
    if (n != NULL)
    {
        inOrder(n->left);
        //print node data;
        inOrder(n->right);
    }
}

void preOrder(Node* n)
{
    if (n != NULL)
    {
        //print node data;
        preOrder(n->left);
        preOrder(n->right);
    }
}

void postOrder(Node* n)
{
    if (n != NULL)
    {
        postOrder(n->left);
        postOrder(n->right);
        //print node data;
    }
}