#include "list.h"

void initialize(List* l) // also empties the list
{
    l->head = NULL;
}

bool isEmpty(List* l)
{
    if(l->head == NULL)
        return true;
    else
        return false;
}

void append(List* l, int value) // add an element at final of the list
{
    Node* n = l->head;

    while (n->next != NULL)
    {
        n = n->next;
    }

    n->next = malloc(sizeof(Node));
    n->next->data = value;
    n->next->next = NULL;
}

int remove(List* l) // remove the element at final of the list
{
    int ret = 0;
    if(l->head->next == NULL)
    {
        ret = l->head->data;
        free(l);
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