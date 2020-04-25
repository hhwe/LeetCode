/* 给你一个由 '('、')' 和小写字母组成的字符串 s。

你需要从字符串中删除最少数目的 '(' 或者 ')' （可以删除任意位置的括号)，使得剩下的「括号字符串」有效。

请返回任意一个合法字符串。

有效「括号字符串」应当符合以下 任意一条 要求：

空字符串或只包含小写字母的字符串
可以被写作 AB（A 连接 B）的字符串，其中 A 和 B 都是有效「括号字符串」
可以被写作 (A) 的字符串，其中 A 是一个有效的「括号字符串」
 

示例 1：

输入：s = "lee(t(c)o)de)"
输出："lee(t(c)o)de"
解释："lee(t(co)de)" , "lee(t(c)ode)" 也是一个可行答案。
示例 2：

输入：s = "a)b(c)d"
输出："ab(c)d"
示例 3：

输入：s = "))(("
输出：""
解释：空字符串也是有效的
示例 4：

输入：s = "(a(b(c)d)"
输出："a(b(c)d)"
 

提示：

1 <= s.length <= 10^5
s[i] 可能是 '('、')' 或英文小写字母
通过次数5,415提交次数9,840

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-remove-to-make-valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

#include "solution.h"

#define INIT_STACK_MAX_SIZE 10000

typedef int ElemType;

typedef struct
{
    ElemType *base;
    ElemType *top;
    int maxSize;
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
    stack->maxSize = INIT_STACK_MAX_SIZE;
    return stack;
}

void StackFree(Stack *stack)
{
    if (!stack)
    {
        if (!stack->base)
        {
            free(stack->base);
            stack->top = stack->base;
            stack->maxSize = INIT_STACK_MAX_SIZE;
        }
        free(stack);
    }
}

bool StackFull(Stack *stack)
{
    return (stack->top - stack->base) == stack->maxSize;
}

bool StackEmpty(Stack *stack)
{
    return stack->top == stack->base;
}

int StackSize(Stack *stack)
{
    return stack->top - stack->base;
}

ElemType StackGetTop(Stack *stack)
{
    if (StackEmpty(stack))
    {
        printf("Stack Empty\r\n");
        return 0;
    }
    return *(stack->top - 1);
}

void StackPush(Stack *stack, ElemType elem)
{
    if (StackFull(stack))
    {
        printf("Stack Full\r\n");
        int newStackSize = stack->maxSize * 2;
        ElemType *newBase = (ElemType *)realloc(stack->base, sizeof(ElemType) * newStackSize);
        if (!newBase)
        {
            printf("Alloc Failed\r\n");
            exit(1);
        }
        stack->base = newBase;
        stack->maxSize = newStackSize;
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

char *minRemoveToMakeValid(char *s)
{
    int len = strlen(s);
    Stack *stack = StackInit();
    int a[100] = {0};
    int index = 0;

    for (int i = 0; i < len; i++)
    {
        if (s[i] == ')' && StackGetTop(stack) == '(')
        {
            StackPop(stack);
            index--;
        }
        else if (s[i] == '(' || s[i] == ')')
        {
            StackPush(stack, s[i]);
            a[index] = i;
            index++;
        }
    }

    if (StackEmpty(stack))
    {
        return s;
    }

    char *ret = (char *)malloc(sizeof(char) * len + 1);
    int indexTmp = 0;
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if (a[indexTmp] == i && indexTmp < index)
        {
            indexTmp++;
            continue;
        }
        ret[j++] = s[i];
    }
    ret[j] = '\0';

    return ret;
}
