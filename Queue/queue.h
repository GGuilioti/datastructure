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

void initialize(Queue* q); // also empties the queue

bool isEmpty(Queue* q);

void add(Queue* q, int value);

int remove(Queue* q);

int first(Queue* q);


