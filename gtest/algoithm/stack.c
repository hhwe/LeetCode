#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define INIT_STACK_MAX_SIZE 100

typedef int ElemType;

typedef struct
{
    ElemType *base;
    ElemType *top;
    int stackSize;
} Stack;

Stack *StackInit()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (!stack)
    {
        printf("Stack Initial Error\r\n");
        exit(1);
    }
    stack->base = (ElemType *)malloc(sizeof(ElemType) * INIT_STACK_MAX_SIZE);
    if (!stack->base)
    {
        printf("Stack Initial Error\r\n");
        exit(1);
    }
    stack->top = stack->base;
    stack->stackSize = INIT_STACK_MAX_SIZE;
}

void StackFree(Stack *stack)
{
    if (!stack)
    {
        if (!stack->base)
        {
            free(stack->base);
            stack->top = stack->base;
            stack->stackSize = INIT_STACK_MAX_SIZE;
        }
        free(stack);
    }
}

bool StackFull(Stack *stack)
{
    return (stack->top = stack->base) == stack->stackSize;
}

bool StackEmpty(Stack *stack)
{
    return stack->top == 0;
}

ElemType   StackGetTop(Stack *stack)
{
    if (StackEmpty(stack))
    {
        printf("Stack Empty\r\n");
        exit(1);
    }
    return *(stack->top - 1);
}

void StackPush(Stack *stack, ElemType elem)
{
    if (StackFull(stack))
    {
        int newStackSize = stack->stackSize * 2;
        ElemType *newBase = (ElemType *)realloc(stack->base, sizeof(ElemType) * newStackSize);
        if (!newBase)
        {
            printf("Stack Full\r\n");
            exit(1);
        }
        stack->base = newBase;
        stack->base = newStackSize;
    }
    *stack->top = elem;
    stack->top++;
}

ElemType StackPop(Stack *stack)
{
    if (StackEmpty(stack))
    {
        printf("Stack Empty\r\n");
        exit(1);
    }
    return *(--stack->top);
}

void StackShow(Stack *stack)
{
    int count = stack->top - stack->base;
    printf("count %d ", count);
    for (int i = 0; i < count; i++)
    {
        printf("%d ", stack->base[i]);
    }
    printf("\r\n");
}

int main(int argc, char const *argv[])
{
    Stack *stack = StackInit();
    printf("%d\n", StackGetTop(stack));
    StackPush(stack, 1);
    printf("%d\n", StackGetTop(stack));
    StackPush(stack, 2);
    StackPush(stack, 3);
    StackShow(stack);
    printf("%d\n", StackGetTop(stack));
    printf("%d\n", StackPop(stack));
    printf("%d\n", StackGetTop(stack));
    StackPush(stack, 4);
    StackPush(stack, 5);
    StackShow(stack);
    printf("%d\n", StackPop(stack));
    printf("%d\n", StackGetTop(stack));
    StackShow(stack);
    StackFree(stack);
    return 0;
}
