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

int size(List* l);

int elementAt(List* l, int pos);

// add an element on final of the list
void append(List* l, int value);

void insertAt(List* l, int value, int pos);

 // remove an element on final of the list
int remove(List* l);

int removeAt(List* l, int pos);

//result is l1 + l2
void merge(List* l1, List* l2);

// pos must be >= 1 where 1 is the first element
List* split(List* l, int pos);

List* copy(List* l);