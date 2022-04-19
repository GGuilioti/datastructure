#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    Node* next;
}Node;

typedef struct list
{
    Node* head;
    int size;
}List;

// also empties the list
void initialize(List* l); 

bool empty(List* l);

// add an element on final of the list
void append(List* l, int value);

 // remove an element on final of the list
int remove(List* l);

int elementAt(List* l, int pos);

int size(List* l);

