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
}Stack;

void initialize(Stack* s); // also empties the stack

bool isEmpty(Stack* s);

void push(Stack* s, int value);

int pop(Stack* s);

int top(Stack* s);

