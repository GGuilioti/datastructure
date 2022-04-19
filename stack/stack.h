#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    Node* next;
}Node;

typedef struct stack
{
    Node* top;
    int size;
}Stack;

 // also empties the stack
void initialize(Stack* s);

bool empty(Stack* s);

void push(Stack* s, int value);

int pop(Stack* s);

int top(Stack* s);

int size(Stack* s);

