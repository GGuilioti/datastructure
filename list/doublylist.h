#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    Node* next;
    Node* prev;
}Node;

typedef struct doublylist
{
    Node* head;
}DoublyList;

// also empties the list
void initialize(DoublyList* d); 

bool empty(DoublyList* d);

int size(DoublyList* d);

int elementAtIndex(DoublyList* d, int index);

// negative for add in final, 0 to add in begin or positive to add at index
void insert(DoublyList* d, int value, int index);

// negative for remove in final, 0 to remove in begin or positive to remove at index
int removeAtIndex(DoublyList* d, int index);

//result is l1 + l2
void merge(DoublyList* d1, DoublyList* d2);

// pos must be >= 1 where 1 is the first element
DoublyList* split(DoublyList* d, int index);

DoublyList* copy(DoublyList* d);

void sortedInsert(DoublyList* d, int value);

//removes the first element found equals to value
int remove(DoublyList* d, int value);
