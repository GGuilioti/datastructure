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
List* initialize(List* l); 

bool empty(List* l);

int size(List* l);

int elementAtIndex(List* l, int index);

// negative for add in final, 0 to add in begin or positive to add at index
void insert(List* l, int value, int index);

// negative for remove in final, 0 to remove in begin or positive to remove at index
int removeAtIndex(List* l, int index);

//result is l1 + l2
void merge(List* l1, List* l2);

// pos must be >= 1 where 1 is the first element
List* split(List* l, int index);

List* copy(List* l);

void sortedInsert(List* l, int value);

//removes the first element found equals to value
int remove(List* l, int value);