#include "binarysearchtree.h"

BinarySearchTree* initialize(BinarySearchTree* b)
{
    b->root = NULL;
}

bool empty(BinarySearchTree* b)
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

Node* minimumIterative(Node* n)
{
    Node* n2 = n;

    if(n2 != NULL)
    {
        while (n2->left != NULL)
        {
            n2 = n2->left;
        }
    }

    return n2;
}

Node* minimumRecursive(Node* n)
{
    if((n == NULL) || (n->left == NULL))
        return n;
    else
        return minimumRecursive(n->left);
}

Node* maximumIterative(Node* n)
{
    Node* n2 = n;

    if(n2 != NULL)
    {
        while (n2->right != NULL)
        {
            n2 = n2->right;
        }
    }

    return n2;
}

Node* maximumRecursive(Node* n)
{
    if((n == NULL) || (n->right == NULL))
        return n;
    else
        return maximumRecursive(n->right);
}

Node* searchItarative(Node* n, int value)
{
    Node* n2 = n;

    while ((n2 != NULL) && (n2->data != value))
    {
        if(value < n2->data)
            n2 = n2->left;
        else
            n2 = n2->right;
    }
    
    return n2;
}

Node* searchRecursive(Node* n, int value)
{
    if((n == NULL) || (n->data == value))
        return n;
    else
    {
        if(value < n->data)
            return searchRecursive(n->left, value);
        else
            return searchRecursive(n->right, value);
    }
}

void insert(Node* n, int value)
{
    if(n == NULL)
    {
        n = malloc(sizeof(Node));
        n->data = value;
        n->left = NULL;
        n->right = NULL;
    }
    else
    {
        if(value < n->data)
            insert(n->left, value);
        else
        {
            if(value > n->data)
                insert(n->right, value);
        }
    }
}

int remove(Node* n, int value)
{
    if(n != NULL)
    {
        if(value < n->data)
            remove(n->left, value);
        else
        {
            if(value > n->data)
                remove(n->right, value);
            else
            {
                if((n->left != NULL) && (n->right != NULL))
                {
                    Node* n2 = minimumRecursive(n->right);
                    n->data = n2->data;
                    remove(n->right, n2->data);
                }
                else
                {
                    Node* n2 = n;
                    
                    if(n->left == NULL)
                        n = n->right;
                    else
                        n = n->left;
                    
                    free(n2);
                }
            }
        }
    }
}