#include "stack.h"

void initialize(Stack* s) // also empties the stack
{
    s->top = NULL;
}

bool isEmpty(Stack* s)
{
    if(s->top == NULL)
        return false;
    else 
        return true;
}

void push(Stack* s, int value)
{
    Node* q = malloc(sizeof(Node));
    q->data = value;
    q->next = s->top;
    s->top = q;
    free(q);
}

int pop(Stack* s)
{
    if(!isEmpty(s))
    {
        Node* q = malloc(sizeof(Node));
        q = s->top;
        int key = q->data;
        s->top = s->top->next;
        free(q);
        
        return key;
    }
}

int top(Stack* s)
{
    if(!isEmpty(s))
        return s->top->data;
}