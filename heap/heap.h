#define length 100

typedef struct heap
{
    int data[length];
    int size;
} Heap;

int Parent(int index);

int Left(int index);

int Right(int index);

int MaxHeapify(Heap heap, int index);

Heap BuildMaxHeap(Heap heap);

void swamp(int *a, int *b);