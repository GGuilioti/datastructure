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

Node* moveLeftRed(Node* n)
{
    changeColor(n);
    if(color(n->right->left) == RED)
    {
        n->right = rightRotate(n->right);
        n = leftRotate(n);
        changeColor(n);
    }
    return n;
}

Node* moveRightRed(Node* n)
{
    changeColor(n);
    if(color(n->left->left) == RED)
    {
        n->right = rightRotate(n->right);
        n = rightRotate(n);
        changeColor(n);
    }
    return n;
}

Node* balance(Node* n)
{
    if(color(n->right) == RED)
        n = leftRotate(n);

    if(n->left != NULL && color(n->left) == RED && cor(n->left->left) == RED)
        n = rightRotate(n);

    if(color(n->left) == RED && color(n->right) == RED)
        changeColor(n);

    return n;
}

int insert(RedBlackTree* rb, int value)
{
    int ret;

    rb->root = insertNode(rb->root, value, &ret);
    if(rb->root != NULL)
        rb->root->color = BLACK;

    return ret;
}

Node* insertNode(Node* n, int value, int *ret)
{
    if(n == NULL)
    {
        Node* new;
        new = malloc(sizeof(Node));

        if(new == NULL)
        {
            *ret = 0;
            return NULL;
        }

        new->data = value;
        new->color = RED;
        new->left = NULL;
        new->right = NULL;
        *ret = 1;
        return new;
    }

    if(value == n->data)
        *ret = 0;
    else
    {
        if(value < n->data)
            n->left = insertNode(n->left, value, ret);
        else
            n->right = insertNode(n->right, value, ret);
    }

    if(color(n->right) == RED && color(n->left) == BLACK)
        n = leftRotate(n);

    if(color(n->left) == RED && color(n->left->left) == RED)
        n = rightRotate(n);
    
    if(color(n->left) == RED && color(n->right) == RED)
        changeColor(n);

    return n;
}

int remove(RedBlackTree* rb, int value)
{
    if(consulta(rb, value))
    {
        Node* aux = rb;

        rb = removeNode(aux, value);
        if(rb != NULL)
            rb->root->color = BLACK;
        return 1;
    }
    else
        return 0;
}

Node* removeNode(Node* n, int value)
{
    if(value < n->data)
    {
        if(color(n->left) == BLACK && color(n->left->left) == BLACK)
            n = moveLeftRed(n);
        
        n->left = removeNode(n->left, value);
    }
    else
    {
        if(color(n->left) == RED)
            n = rightRotate(n);

        if(value == n->data && (n->right == NULL))
        {
            free(n);
            return NULL;
        }

        if(color(n->right) == BLACK && color(n->right->left) == BLACK)
            n = moveRightRed(n);

        if(value == n->data)
        {
            Node* aux = minimum(n->right);
            n->data = aux->data;
            n->right = removeMinimum(n->right);
        }else
            n->right = removeNode(n->right, value);
    }
    return balance(n);
}

Node* removeMinimum(Node* n)
{
    if(n->left == NULL)
    {
        free(n);
        return NULL;
    }
    if(color(n->left) == BLACK && color(n->left->left) == BLACK)
        n = moveLeftRed(n);
    
    n->left = removeMinimum(n->left);
    return balance(n);
}

Node* minimum(Node* n)
{
    Node* aux = n;
    Node* aux2 = n->left;

    while(aux2 != NULL)
    {
        aux = aux2;
        aux2 = aux2->left;
    }
    return aux;
}