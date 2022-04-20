#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    Node* next;
}Node;

typedef struct headerlist
{
    Node* head;
}HeaderList;

// also empties the headerlist
void initialize(HeaderList* l); 

bool empty(HeaderList* l);

int size(HeaderList* l);

int elementAtIndex(HeaderList* l, int index);

// negative for add in final, 0 to add in begin or positive to add at index
void insert(HeaderList* l, int value, int index);

// negative for remove in final, 0 to remove in begin or positive to remove at index
int removeAtIndex(HeaderList* l, int index);

//result is l1 + l2
void merge(HeaderList* l1, HeaderList* l2);

// pos must be >= 1 where 1 is the first element
HeaderList* split(HeaderList* l, int index);

HeaderList* copy(HeaderList* l);

void sortedInsert(HeaderList* l, int value);

//removes the first element found equals to value
int remove(HeaderList* l, int value);