#include "deque.h"

void initialize(Deque* d)
{
    d->left = NULL;
    d->right = NULL;
}

bool empty(Deque* d)
{
    if(d->left == NULL)
        return true;
    else
        return false;
}

void addLeft(Deque* d, int value)
{
    Node* n = malloc(sizeof(Node));
    n->data = value;

    if(empty(d))
    {
        d->right = n;
    }

    n->next = d->left;
    d->left = n;
}

void addRight(Deque* d, int value)
{
    if(empty(d))
        addLeft(d, value);
    else
    {
        Node* n = malloc(sizeof(Node));
        n->data = value;
        n->next = NULL;

        d->right->next = n;
        d->right = n;
    }
}

int removeLeft(Deque* d)
{
    if(!empty(d))
    {
        int x = d->left->data;

        Node* n = d->left;

        d->left = d->left->next;

        free(n);

        if(empty(d))
            d->right = NULL;

        return x;
    }
}

int removeRight(Deque* d)
{
    if(!empty(d))
    {
        int x = d->right->data;

        if(d->left == d->right)
        {
            free(d->left);
            initialize(d);
        }
        else
        {
            Node* n = d->right;
            d->right = d->left;

            while(d->right->next != n)
            {
                d->right = d->right->next;
            }

            d->right->next = NULL;

            free(n);
        }

        return x;
    }
}

int right(Deque* d)
{
    if(!empty(d))
        return d->right->data;
}

int left(Deque* d)
{
    if(!empty(d))
        return d->left->data;
}