#include <stdio.h>
#include <stdlib.h>

#include "priorityqueue.h"

int Parent(int index)
{
    return index/2;
}

int Left(int index)
{
    return 2*index;
}

int Right(int index)
{
    return 2*index +1;
}

int MaxHeapify(PriorityQueue heap, int index)
{
    int l = Left(index);
    int r = Right(index);
    int largest;

    if(l <= heap.size && heap.data[l].value > heap.data[r].value)
        largest = l;
    else
        largest = index;

    if(r <= heap.size && heap.data[r].value > heap.data[largest].value)
        largest = r;

    if(largest != index)
    {
        swap(heap.data[index].value, heap.data[largest].value);

        MaxHeapify(heap, largest);
    }
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int Maximum(PriorityQueue heap)
{
    return heap.data[1].value;
}

Node ExtractMax(PriorityQueue heap)
{
    Node max;

    if(heap.size < 1)   
        //Error Handling;
        return;
    
    max = heap.data[1];

    heap.data[1] = heap.data[heap.size];

    heap.size = heap.size -1;

    MaxHeapify(heap, 1);

    return max;
}

PriorityQueue IncreaseKey(PriorityQueue heap, int index, int key)
{
    if(key < heap.data[index].priority)
        //Error Handling;
        return;
    heap.data[index].priority = key;

    Node aux;
    while (index > 1 && heap.data[Parent(index)].priority < heap.data[index].priority)
    {
        aux = heap.data[Parent(index)];
        heap.data[Parent(index)] = heap.data[index];
        heap.data[index] = aux;

        index = Parent(index);
    }

    return heap;
}

PriorityQueue Insert(PriorityQueue heap, int value, int key)
{
    heap.size++;

    heap.data[heap.size].value = value;
    heap.data[heap.size].priority = -2147483647 - 1;

    IncreaseKey(heap, heap.size, key);

    return heap;
}
    