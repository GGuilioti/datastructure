#include "stack.h"

// also empties the stack
void initialize(Stack* s)
{
    s->top = NULL;
    s->size = 0;
}

bool empty(Stack* s)
{
    if(s->size == 0)
        return true;
    else
        return false;
}

int size(Stack* s)
{
    return s->size;
}

int top(Stack* s)
{
    if(!empty(s))
        return s->top->data;
}

void push(Stack* s, int value)
{
    Node* q = malloc(sizeof(Node));
    q->data = value;
    q->next = s->top;
    s->top = q;
    free(q);
    s->size += 1;
}

int pop(Stack* s)
{
    if(!empty(s))
    {
        Node* q = malloc(sizeof(Node));
        q = s->top;
        int key = q->data;
        s->top = s->top->next;
        free(q);

        s->size -= 1;

        return key;
    }
}

int elementAt(Stack* s, int pos)
{
    Node* n = s->top;

    int count = 0;
    while(count < pos-1)
    {
        n = n->next;
        count++;
    }
    
    return n->data;
}