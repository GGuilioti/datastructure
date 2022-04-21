#include "list.h"

// also empties the list
List* initialize(List* l)
{
    l->head = NULL;
    return l;
}

bool empty(List* l)
{
    if(l->head == NULL)
        return true;
    else
        return false;
}

int size(List* l)
{
    if(!empty(l))
    {
        Node* n = l->head;

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

int elementAtIndex(List* l, int index)
{
    Node* n = l->head;

    int count = 0;
    while(count < index)
    {
        n = n->next;
        count++;
    }
    
    return n->data;
}

void insert(List* l, int value, int index)
{

    //final
    if(index < 0)
    {
        Node* n = l->head;

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
        n->next = l->head;
        l->head = n;
    }
    //index
    else
    {
        Node* n = l->head;

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

int removeAtIndex(List* l, int index)
{
    Node* n = l->head;

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
        l->head = l->head->next;

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

// index must be >= 1 where 1 is the first element
List* split(List* l, int index)
{
    if(!empty(l) && (index < size(l)))
    {
        if(index <= 0)
            return;

        Node* n = l->head;

        int count = 1;
        while(count < index-1)
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
    Node* aux = l->head;
    List* l2 = initialize(l2);
    while (aux->next != NULL)
    {
        insert(l2, aux->data, -1);
        aux = aux->next;
    }

    insert(l2, aux->data, -1);
    
    return l2;
}

void sortedInsert(List* l, int value)
{
    Node* n = malloc(sizeof(Node));
    n->data = value;

    if(empty(l) || value <= l->head->data)
    {
        n->next = l;
        l = n;
    }
    else
    {
        Node* aux = l;
        while ((aux->next != NULL) && (aux->next->data < value))
        {
            aux = aux->next;
        }

        n->next = aux->next;
        aux->next = n;
    }
}

//removes the first element found equals to value
int remove(List* l, int value)
{
    int ret = 0;
    if(!empty(l))
    {
        if(l->head->data = value)
        {
            Node* n = l;
            l->head->next = l->head->next->next;
            ret = n->data;
            free(n);
            return ret;
        }
        else
        {
            Node* aux = l;

            while ((aux->next != NULL) && (aux->next->data != value))
            {
                aux = aux->next;
            }
            
            if(aux->next != NULL)
            {
                Node* n = aux->next;
                aux->next = n->next;
                ret = n->data;
                free(n);
                return ret;
            }
        }
    }
}