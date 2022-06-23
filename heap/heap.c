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
    int bigger;

    if(l <= heap.size && heap.data[l] > heap.data[r])
        bigger = l;
    else
        bigger = index;

    if(r <= heap.size && heap.data[r] > heap.data[bigger])
        bigger = r;

    if(bigger != index)
    {
        int aux = heap.data[index];
        heap.data[index] = heap.data[bigger];
        heap.data[bigger] = aux;

        MaxHeapify(heap, bigger);
    }
}