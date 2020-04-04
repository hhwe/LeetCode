#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define INIT_HEAP_MAX_SIZE 3

typedef int ElemType;

typedef struct
{
    ElemType *base;
    ElemType *top;
    int stackSize;
} Heap;

Heap *HeapInit()
{
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    if (!heap)
    {
        printf("Heap Initial Error\r\n");
        exit(1);
    }
    heap->base = (ElemType *)malloc(sizeof(ElemType) * INIT_HEAP_MAX_SIZE);
    if (!heap->base)
    {
        printf("Heap Initial Error\r\n");
        exit(1);
    }
    heap->top = heap->base;
    heap->stackSize = INIT_HEAP_MAX_SIZE;
}

void HeapFree(Heap *heap)
{
    if (!heap)
    {
        if (!heap->base)
        {
            free(heap->base);
            heap->top = heap->base;
            heap->stackSize = INIT_HEAP_MAX_SIZE;
        }
        free(heap);
    }
}

bool HeapFull(Heap *heap)
{
    return (heap->top - heap->base) == heap->stackSize;
}

bool HeapEmpty(Heap *heap)
{
    return heap->top == heap->base;
}

ElemType HeapGetTop(Heap *heap)
{
    if (HeapEmpty(heap))
    {
        printf("Heap Empty\r\n");
        exit(1);
    }
    return *(heap->top - 1);
}

void HeapPush(Heap *heap, ElemType elem)
{
    if (HeapFull(heap))
    {
        printf("Heap Full\r\n");
        int newHeapSize = heap->stackSize * 2;
        ElemType *newBase = (ElemType *)realloc(heap->base, sizeof(ElemType) * newHeapSize);
        if (!newBase)
        {
            printf("Alloc Failed\r\n");
            exit(1);
        }
        heap->base = newBase;
        heap->stackSize = newHeapSize;
    }
    *heap->top = elem;
    heap->top++;
}

ElemType HeapPop(Heap *heap)
{
    if (HeapEmpty(heap))
    {
        printf("Heap Empty\r\n");
        exit(1);
    }
    return *(--heap->top);
}

void HeapShow(Heap *heap)
{
    int count = heap->top - heap->base;
    printf("count %d ", count);
    for (int i = 0; i < count; i++)
    {
        printf("%d ", heap->base[i]);
    }
    printf("\r\n");
}

int main(int argc, char const *argv[])
{
    Heap *heap = HeapInit();
    HeapPush(heap, 1);
    printf("%d\n", HeapGetTop(heap));
    HeapPush(heap, 2);
    HeapPush(heap, 3);
    HeapShow(heap);
    printf("%d\n", HeapGetTop(heap));
    printf("%d\n", HeapPop(heap));
    printf("%d\n", HeapGetTop(heap));
    HeapPush(heap, 4);
    HeapPush(heap, 5);
    HeapShow(heap);
    printf("%d\n", HeapPop(heap));
    printf("%d\n", HeapGetTop(heap));
    HeapShow(heap);
    printf("%d\n", HeapPop(heap));
    printf("%d\n", HeapPop(heap));
    printf("%d\n", HeapPop(heap));
    HeapShow(heap);
    HeapFree(heap);
    return 0;
}
