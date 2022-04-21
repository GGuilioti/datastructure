#include "headerlist.h"

// also empties the headerlist
HeaderList* initialize(HeaderList* l)
{
    l->head = malloc(sizeof(Node));
    l->head->next = NULL;
    return l;
}

bool empty(HeaderList* l)
{
    if(l->head->next == NULL)
        return true;
    else
        return false;
}

int size(HeaderList* l)
{
    if(!empty(l))
    {
        Node* n = l->head->next;

        int size = 1;
        while(n->next != NULL)
        {
            n = n->next;
            size++;
        }
        return size;
    }
    else
        return 0;
}

int elementAtIndex(HeaderList* l, int index)
{
    Node* n = l->head->next;

    int count = 0;
    while(count < index)
    {
        n = n->next;
        count++;
    }
    
    return n->data;
}

void insert(HeaderList* l, int value, int index)
{

    //final
    if(index < 0)
    {
        Node* n = l->head->next;

        int count = 0;
        while(count < size(l))
        {
            n = n->next;
            count++;
        }

        n->next = malloc(sizeof(Node));
        n->next->data = value;
        n->next->next = NULL;  
    }
    //begin
    else if(index == 0)
    {
        Node* n = malloc(sizeof(Node));
        n->data = value;
        n->next = l->head->next;
        l->head->next = n;
    }
    //index
    else
    {
        Node* n = l->head->next;

        int count = 0;
        while(count < index-1)
        {
            n = n->next;
            count++;
        }

        Node* n2 = malloc(sizeof(Node));
        n2->data = value;
        n2->next = n->next;
        n->next = n2;
    }
}

int removeAtIndex(HeaderList* l, int index)
{
    Node* n = l->head->next;

    int ret = 0;

    //final
    if(index < 0)
    {
        int count = 0;
        while(count < (size(l) -1))
        {
            n = n->next;
            count++;
        }

        Node* n2 = n->next;
        n->next = NULL;

        ret = n2->data;

        free(n2);

        return ret;
    }
    //begin
    else if(index == 0)
    {
        l->head->next = l->head->next->next;

        ret = n->data;

        free(n);

        return ret;
    }
    //index
    else
    {
        int count = 0;
        while(count < index-1)
        {
            n = n->next;
            count++;
        }

        Node* n2 = n->next;
        n->next = n2->next;
        n2->next = NULL;

        ret = n2->data;

        free(n2);

        return ret;
    }
}

void merge(HeaderList* l1, HeaderList* l2)
{
    if(empty(l1))
    {
        l1 = l2;
    }
    else
    {
        if(empty(l2))
            return;
        
        Node* n = l1->head->next;
        while (n->next->next != NULL)
        {
            n = n->next;
        }

        n->next->next = l2;
    }
}

// pos must be >= 1 where 1 is the first element
HeaderList* split(HeaderList* l, int index)
{
    if(!empty(l) && (index < size(l)))
    {
        if(index <= 0)
            return;

        Node* n = l->head->next;

        int count = 0;
        while(count < index-1)
        {
            n = n->next;
            count++;
        }

        HeaderList* l2 = n->next;
        n->next = NULL; 

        return l2;
    }
}

HeaderList* copy(HeaderList* l)
{
    Node* aux = l->head->next;
    HeaderList* l2 = initialize(l2);
    while (aux->next != NULL)
    {
        insert(l2, aux->data, -1);
        aux = aux->next;
    }

    insert(l2, aux->data, -1);
    
    return l2;
}

void sortedInsert(HeaderList* l, int value)
{
    Node* n = malloc(sizeof(Node));
    n->data = value;

    Node* aux = l;

    while ((aux->next != NULL) && (aux->next->data < value))
    {
        aux = aux->next;
    }
    
    n->next = aux->next;
    aux->next = n;
}

//removes the first element found equals to value
int remove(HeaderList* l, int value)
{
    Node* n = l;
    int ret = 0;

    while ((n->next != NULL) && (n->next->data != value))
    {
        n = n->next;
    }
    
    if(n->next != NULL)
    {
        Node* aux = n->next;
        n->next = aux->next;

        ret = aux->data;
        free(aux);

        return ret;
    }
}