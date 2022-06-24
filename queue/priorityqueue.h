#define LENGHT 100

typedef struct node
{
    int value;
    int priority;
} Node;

typedef struct priorityqueue
{
    Node data[LENGHT];
    int size;
} PriorityQueue;

int Parent(int index);

int Left(int index);

int Right(int index);

int MaxHeapify(PriorityQueue heap, int index);

void Swap(int *a, int *b);

int Maximum(PriorityQueue heap);

Node ExtractMax(PriorityQueue heap);

PriorityQueue IncreaseKey(PriorityQueue heap, int index, int key);

PriorityQueue Insert(PriorityQueue heap, int value, int key);