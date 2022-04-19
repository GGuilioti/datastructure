#include "list.h"

// also empties the list
void initialize(List* l)
{
    l->head = NULL;
    l->size = 0;
}

bool empty(List* l)
{
    if(l->size == 0)
        return true;
    else
        return false;
}

// add an element at final of the list
void append(List* l, int value)
{
    Node* n = l->head;

    while (n->next != NULL)
    {
        n = n->next;
    }

    n->next = malloc(sizeof(Node));
    n->next->data = value;
    n->next->next = NULL;

    l->size += 1;
}

// remove the element at final of the list
int remove(List* l)
{
    int ret = 0;
    if(l->head->next == NULL)
    {
        ret = l->head->data;
        free(l);
        l->size -= 1;
        return ret;
    }

    Node* n = l->head;
    while (n->next->next != NULL)
    {
        n = n->next;
    }
    ret = n->next->data;
    free(n->next);
    n->next = NULL;
    return ret;
}

int elementAt(List* l, int pos)
{
    Node* n = l->head;

    int count = 0;
    while(count < pos-1)
    {
        n = n->next;
        count++;
    }
    
    return n->data;
}

int size(List* l)
{
    return l->size;
}