const int lenght = 1000;

typedef struct heap
{
    int data[lenght];
    int size;
} Heap;

int Parent(int index);

int Left(int index);

int Right(int index);

int MaxHeapify(Heap heap, int index);