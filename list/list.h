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
}List;

void initialize(List* l); // also empties the list

bool isEmpty(List* l);

void append(List* l, int value); // add an element on final of the list

int remove(List* l); // remove an element on final of the list

int elementAt(List* l, int pos);

