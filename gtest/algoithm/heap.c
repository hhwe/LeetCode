/* 
 * 小顶堆
 * 以上是堆的性质。下面是如何构造一个堆：

 

堆的构造：数组，count表示内容大小，maxSize表示最大容量。
堆的判空、返回大小、初始化都很简单，直接返回性质（具体看最后代码）。
入堆：入堆需要判断他的大小，方法是：先将他放在最后面的位置（如图），然后依次和他的父亲比较，只要比父亲大，就交换。
出堆：直接取走顶端元素（arr[1]），然后把最后的元素挪到最前面，然后把它进行下移的操作。最后把数组最后一个元素删掉，并且count - 1就完成了。
 */
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
} MinHeap;

MinHeap *HeapInit()
{
    MinHeap *heap = (MinHeap *)malloc(sizeof(MinHeap));
    if (!heap)
    {
        printf("MinHeap Initial Error\r\n");
        exit(1);
    }
    heap->nodes = (ElemType *)malloc(sizeof(ElemType) * INIT_HEAP_MAX_SIZE);
    if (!heap->nodes)
    {
        printf("MinHeap Initial Error\r\n");
        exit(1);
    }
    heap->count = 0;
    heap->maxSize = INIT_HEAP_MAX_SIZE;
}

void HeapFree(MinHeap *heap)
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

bool HeapFull(MinHeap *heap)
{
    return heap->count == heap->maxSize;
}

bool HeapEmpty(MinHeap *heap)
{
    return heap->count == 0;
}

ElemType HeapGetTop(MinHeap *heap)
{
    if (HeapEmpty(heap))
    {
        printf("MinHeap Empty\r\n");
        exit(1);
    }
    return heap->nodes[heap->count - 1];
}

void HeapInsert(MinHeap *heap, ElemType elem)
{
    if (HeapFull(heap))
    {
        printf("MinHeap Full\r\n");
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

ElemType HeapRemove(MinHeap *heap)
{
    if (HeapEmpty(heap))
    {
        printf("MinHeap Empty\r\n");
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

void HeapShow(MinHeap *heap)
{
    for (int i = 0; i < heap->count; i++)
    {
        printf("%d ", heap->nodes[i]);
    }
    printf("\r\n");
}

int TestHeap()
{
    MinHeap *heap = HeapInit();
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

int nthUglyNumber(int n)
{
    MinHeap *heap = HeapInit();
    int ret = 1;
    HeapInsert(heap, 1);
    for (int i = 1; i < n; i++)
    {
        int top = HeapGetTop(heap);
        ret = HeapRemove(heap);
        if (top < ret * 5)
        {
            HeapInsert(heap, ret * 5);
            if (top < ret * 3)
            {
                HeapInsert(heap, ret * 3);
                if (top < ret * 5)
                {
                    HeapInsert(heap, ret * 2);
                }
            }
        }
    }
    HeapShow(heap);
    return ret;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", nthUglyNumber(10));
    return 0;
}
