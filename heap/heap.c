#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

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

int MaxHeapify(Heap heap, int index)
{
    int l = Left(index);
    int r = Right(index);
    int largest;

    if(l <= heap.size && heap.data[l] > heap.data[r])
        largest = l;
    else
        largest = index;

    if(r <= heap.size && heap.data[r] > heap.data[largest])
        largest = r;

    if(largest != index)
    {
        swap(heap.data[index], heap.data[largest]);

        MaxHeapify(heap, largest);
    }
}

Heap BuildMaxHeap(Heap heap)
{
    heap.size = length;

    for (int i = (length/2); i >= 0; i--)
    {
        MaxHeapify(heap, i);
    }

    return heap;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}