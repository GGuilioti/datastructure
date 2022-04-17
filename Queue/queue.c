#include "queue.h"

void initialize(Queue* q) // also empties the queue
{
    q->front = NULL;
    q->rear = NULL;
}

bool isEmpty(Queue* q)
{
    if(q->front == NULL)
        return true;
    else
        return false;
}

void add(Queue* q, int value)
{
    Node* r = malloc(sizeof(Node));
    r->data = value;
    r->next = NULL;
    
    if(isEmpty(q))
        q->front = r;
    else
        q->rear->next = r;
    
    q->rear = r;
}

int remove(Queue* q)
{
    int x;
    if(!isEmpty(q))
    {
        Node* r = q->front;
        x = r->data;

        q->front = q->front->next;
        free(r);

        if (isEmpty(q))
            q->rear = NULL;
    }

    return x;
}

int first(Queue* q)
{
    if(!isEmpty(q))
        return q->front->data;
}

