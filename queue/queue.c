#include "queue.h"

// also empties the queue
void initialize(Queue* q)
{
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

bool empty(Queue* q)
{
    if(q->size == 0)
        return true;
    else
        return false;
}

void add(Queue* q, int value)
{
    Node* r = malloc(sizeof(Node));
    r->data = value;
    r->next = NULL;
    
    if(empty(q))
    {
        q->front = r;
        q->size += 1;
    }
    else
    {
        q->rear->next = r;
        q->size += 1;
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

        q->size -= 1;

        if (empty(q))
            q->rear = NULL;
    }

    return x;
}

int first(Queue* q)
{
    if(!empty(q))
        return q->front->data;
}

int size(Queue* q)
{
    return q->size;
}

