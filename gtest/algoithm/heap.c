#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define INIT_HEAP_MAX_SIZE 100

typedef int ElemType;

typedef struct
{
    ElemType *nodes;
    int count;
    int maxSize;
} Heap;

Heap *HeapInit()
{
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    if (!heap)
    {
        printf("Heap Initial Error\r\n");
        exit(1);
    }
    heap->nodes = (ElemType *)malloc(sizeof(ElemType) * INIT_HEAP_MAX_SIZE);
    if (!heap->nodes)
    {
        printf("Heap Initial Error\r\n");
        exit(1);
    }
    heap->count = 0;
    heap->maxSize = INIT_HEAP_MAX_SIZE;
}

void HeapFree(Heap *heap)
{
    if (!heap)
    {
        if (!heap->nodes)
        {
            free(heap->nodes);
            heap->count = 0;
            heap->maxSize = INIT_HEAP_MAX_SIZE;
        }
        free(heap);
    }
}

bool HeapFull(Heap *heap)
{
    return heap->count == heap->maxSize;
}

bool HeapEmpty(Heap *heap)
{
    return heap->count == 0;
}

ElemType HeapGetTop(Heap *heap)
{
    if (HeapEmpty(heap))
    {
        printf("Heap Empty\r\n");
        exit(1);
    }
    return heap->nodes[heap->count - 1];
}

void HeapInsert(Heap *heap, ElemType elem)
{
    if (HeapFull(heap))
    {
        printf("Heap Full\r\n");
        int newHeapSize = heap->maxSize * 2;
        ElemType *newBase = (ElemType *)realloc(heap->nodes, sizeof(ElemType) * newHeapSize);
        if (!newBase)
        {
            printf("Alloc Failed\r\n");
            exit(1);
        }
        heap->nodes = newBase;
        heap->maxSize = newHeapSize;
    }
    heap->nodes[heap->count] = elem;
    heap->count++;
    int childNode = heap->count - 1;
    while (childNode)
    {
        int parentNode = (childNode - 1) / 2;
        if (heap->nodes[childNode] >= heap->nodes[parentNode])
        {
            break;
        }
        heap->nodes[childNode] = heap->nodes[parentNode];
        childNode = parentNode;
    }
    heap->nodes[childNode] = elem;
}

ElemType HeapRemove(Heap *heap)
{
    if (HeapEmpty(heap))
    {
        printf("Heap Empty\r\n");
        exit(1);
    }
    ElemType elem = heap->nodes[0];
    ElemType tmp = heap->nodes[heap->count - 1];
    heap->nodes[0] = tmp;
    heap->count--;
    int parentNode = 0;
    int childNode = 2 * parentNode + 1;
    while (childNode < heap->count)
    {
        if (childNode + 1 < (heap->count) && heap->nodes[childNode] > heap->nodes[childNode + 1])
        {
            childNode++;
        }
        if (heap->nodes[parentNode] < heap->nodes[childNode])
        {
            break;
        }
        heap->nodes[parentNode] = heap->nodes[childNode];
        parentNode = childNode;
        childNode = 2 * parentNode + 1;
    }
    heap->nodes[parentNode] = tmp;
    return elem;
}

void HeapShow(Heap *heap)
{
    for (int i = 0; i < heap->count; i++)
    {
        printf("%d ", heap->nodes[i]);
    }
    printf("\r\n");
}

int main(int argc, char const *argv[])
{
    Heap *heap = HeapInit();
    HeapInsert(heap, 1);
    printf("%d\n", HeapGetTop(heap));
    HeapInsert(heap, 2);
    HeapInsert(heap, 3);
    HeapShow(heap);
    printf("%d\n", HeapGetTop(heap));
    printf("%d\n", HeapRemove(heap));
    HeapShow(heap);
    printf("%d\n", HeapGetTop(heap));
    HeapInsert(heap, 4);
    HeapInsert(heap, 5);
    HeapShow(heap);
    printf("%d\n", HeapRemove(heap));
    printf("%d\n", HeapGetTop(heap));
    HeapShow(heap);
    printf("%d\n", HeapRemove(heap));
    printf("%d\n", HeapRemove(heap));
    printf("%d\n", HeapRemove(heap));
    HeapShow(heap);
    HeapFree(heap);
    return 0;
}
