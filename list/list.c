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

int size(List* l)
{
    return l->size;
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

void insertAt(List* l, int value, int pos)
{

    if(pos <= 1)
    {
        Node* n = malloc(sizeof(Node));
        n->data = value;
        n->next = l->head;
        l->head = n;

        l->size += 1;
    }
    else
    {
        Node* n = l->head;

        int count = 1;
        while(count < pos-1)
        {
            n = n->next;
            count++;
        }

        Node* n2 = malloc(sizeof(Node));
        n2->data = value;
        n2->next = n->next;
        n->next = n2;

        l->size += 1;
    }
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

int removeAt(List* l, int pos)
{
    Node* n = l->head;

    int ret = 0;
    if(pos <= 1)
    {
        l->head = l->head->next;

        ret = n->data;

        free(n);

        l->size -= 1;

        return ret;
    }
    else
    {
        int count = 1;
        while(count < pos-1)
        {
            n = n->next;
            count++;
        }

        Node* n2 = n->next;
        n->next = n2->next;
        n2->next = NULL;

        ret = n2->data;

        l->size -= 1;

        free(n2);

        return ret;
    }
}

void merge(List* l1, List* l2)
{
    if(empty(l1))
    {
        l1 = l2;
    }
    else
    {
        if(empty(l2))
            return;
        
        Node* n = l1->head;
        while (n->next->next != NULL)
        {
            n = n->next;
        }

        n->next->next = l2;
    }
}

// pos must be >= 1 where 1 is the first element
List* split(List* l, int pos)
{
    if(!empty(l))
    {
        if(pos <= 0)
            return;

        Node* n = l->head;

        int count = 1;
        while(count < pos-1)
        {
            n = n->next;
            count++;
        }

        List* l2 = n->next;
        n->next = NULL; 

        return l2;
    }
}

List* copy(List* l)
{
    List* l2 = l;
    return l2;
}