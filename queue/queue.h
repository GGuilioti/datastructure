#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    Node* next;
}Node;

typedef struct queue
{
    Node* front;
    Node* rear;
}Queue;

// also empties the queue
Queue* initialize(Queue* q);

bool empty(Queue* q);

int first(Queue* q);

int size(Queue* q);

void add(Queue* q, int value);

int remove(Queue* q);

int elementAt(Queue* q, int pos);

Queue* split(Queue* q, int pos);

Queue* copy(Queue* q);




