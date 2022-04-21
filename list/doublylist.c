#include "doublylist.h"

DoublyList* initialize(DoublyList* d)
{
    d->head = NULL;
    return d;
}

bool empty(DoublyList* d)
{
    if(d->head == NULL)
        return true;
    else
        return false;
}

int size(DoublyList* d)
{
    if(!empty(d))
    {
        Node* n = d->head;

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

int elementAtIndex(DoublyList* d, int index)
{
    Node* n = d->head;

    int count = 0;
    while(count < index)
    {
        n = n->next;
        count++;
    }
    
    return n->data;
}

void insert(DoublyList* d, int value, int index)
{

    //final
    if(index < 0)
    {
        Node* n = d->head;

        int count = 0;
        while(count < size(d))
        {
            n = n->next;
            count++;
        }

        n->next = malloc(sizeof(Node));
        n->next->prev = n;
        n->next->data = value;
        n->next->next = NULL;  
    }
    //begin
    else if(index == 0)
    {
        Node* n = malloc(sizeof(Node));
        n->data = value;
        n->next = d->head;
        n->prev = NULL;
        d->head = n;
    }
    //index
    else
    {
        Node* n = d->head;

        int count = 0;
        while(count < index-1)
        {
            n = n->next;
            count++;
        }

        Node* n2 = malloc(sizeof(Node));
        n2->data = value;
        n2->next = n->next;
        n2->prev = n;
        n->next = n2;
    }
}

int removeAtIndex(DoublyList* d, int index)
{
    Node* n = d->head;

    int ret = 0;

    //final
    if(index < 0)
    {
        int count = 0;
        while(count < (size(d) -1))
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
        d->head = d->head->next;
        d->head->prev = NULL;

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
        n2->next->prev = n;

        ret = n2->data;

        free(n2);

        return ret;
    }
}

void merge(DoublyList* d1, DoublyList* d2)
{
    if(empty(d1))
    {
        d1 = d2;
    }
    else
    {
        if(empty(d2))
            return;
        
        Node* n = d1->head;
        while (n->next->next != NULL)
        {
            n = n->next;
        }

        n->next->next = d2;
        d2->head->prev = n->next;
    }
}

DoublyList* split(DoublyList* d, int index)
{
    if(!empty(d) && (index < size(d)))
    {
        if(index <= 0)
            return;

        Node* n = d->head;

        int count = 1;
        while(count < index-1)
        {
            n = n->next;
            count++;
        }

        DoublyList* d2 = n->next;
        n->next = NULL; 
        d2->head->prev = NULL;

        return d2;
    }
}

DoublyList* copy(DoublyList* d)
{
    Node* aux = d->head;
    DoublyList* d2 = initialize(d2);
    while (aux->next != NULL)
    {
        insert(d2, aux->data, -1);
        aux = aux->next;
    }

    insert(d2, aux->data, -1);
    
    return d2;
}

void sortedInsert(DoublyList* d, int value)
{
    Node* n = malloc(sizeof(Node));
    n->data = value;

    if(empty(d) || value <= d->head->data)
    {
        n->next = d;
        n->prev = NULL;
        d = n;
    }
    else
    {
        Node* aux = d;
        while ((aux->next != NULL) && (aux->next->data < value))
        {
            aux = aux->next;
        }

        n->next = aux->next;
        aux->next->prev = n;
        aux->next = n;
        n->prev = aux;
    }
}

//removes the first element found equals to value
int remove(DoublyList* d, int value)
{
    int ret = 0;
    if(!empty(d))
    {
        if(d->head->data = value)
        {
            Node* n = d;
            d->head->next->prev = NULL;
            d->head = n->next;
            
            ret = n->data;
            free(n);
            return ret;
        }
        else
        {
            Node* aux = d;

            while ((aux->next != NULL) && (aux->next->data != value))
            {
                aux = aux->next;
            }
            
            if(aux->next != NULL)
            {
                Node* n = aux->next;
                aux->next = n->next;
                n->next->prev = aux;
                ret = n->data;
                free(n);
                return ret;
            }
        }
    }
}