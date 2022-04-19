#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    Node* next;
}Node;

typedef struct deque
{
    Node* left;
    Node* right;
}Deque;

void initialize(Deque* d);

bool empty(Deque* d);

void addLeft(Deque* d, int value);

void addRight(Deque* d, int value);

int removeLeft(Deque* d);

int removeRight(Deque* d);

int right(Deque* d);

int left(Deque* d);