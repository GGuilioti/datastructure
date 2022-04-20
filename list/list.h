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

// also empties the list
void initialize(List* l); 

bool empty(List* l);

int size(List* l);

int elementAt(List* l, int pos);

// negative for add in final, 0 to add in begin or positive to add at index
void add(List* l, int value, int index);

// negative for remove in final, 0 to remove in begin or positive to remove at index
int remove(List* l, int index);

//result is l1 + l2
void merge(List* l1, List* l2);

// pos must be >= 1 where 1 is the first element
List* split(List* l, int pos);

List* copy(List* l);