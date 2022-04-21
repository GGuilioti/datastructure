#include "queue.h"

// also empties the queue
Queue* initialize(Queue* q)
{
    q->front = NULL;
    q->rear = NULL;

    return q;
}

bool empty(Queue* q)
{
    if(q->front == NULL)
        return true;
    else
        return false;
}

int first(Queue* q)
{
    if(!empty(q))
        return q->front->data;
}

int size(Queue* q)
{
    if(!empty(q))
    {
        Node* n = q->front;

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

void add(Queue* q, int value)
{
    Node* r = malloc(sizeof(Node));
    r->data = value;
    r->next = NULL;
    
    if(empty(q))
    {
        q->front = r;
    }
    else
    {
        q->rear->next = r;
    }
    
    q->rear = r;
}

int remove(Queue* q)
{
    int x;
    if(!empty(q))
    {
        Node* r = q->front;
        x = r->data;

        q->front = q->front->next;
        free(r);

        if (empty(q))
            q->rear = NULL;
    }

    return x;
}

int elementAt(Queue* q, int pos)
{
    Node* n = q->front;

    int count = 0;
    while(count < pos-1)
    {
        n = n->next;
        count++;
    }
    
    return n->data;
}

Queue* split(Queue* q, int pos)
{
    if(!empty(q) && (pos < size(q)))
    {
        if(pos <= 0)
            return;

        Node* n = q->front;

        int count = 1;
        while(count < pos-1)
        {
            n = n->next;
            count++;
        }

        Queue* q2;
        q2->rear = q->rear;
        q2->front = n->next;
        q->rear = n;
        q->rear->next = NULL;

        return q2;
    }
}

Queue* copy(Queue* q)
{
    Node* aux = q->front;
    Queue* q2 = initialize(q2);
    while (aux->next != NULL)
    {
        add(q2, aux->data);
        aux = aux->next;
    }

    insert(q2, aux->data);
    
    return q2;
}



