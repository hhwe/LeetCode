#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int IsValid(char *s, int size)
{
    int a = 0;
    for (int i = 0; i < size; i++)
    {
        if (s[i] == '(')
        {
            a++;
        }
        else if (s[i] == ')')
        {
            a--;
        }
        if (a < 0)
        {
            return 0;
        }
    }
    return a == 0;
}

void Recursion(int n, char *s, int nn, char **ss, int *size)
{
    if (n <= 0)
    {
        if (IsValid(s, nn))
        {
            s[nn] = '\0';
            memcpy(ss[*size], s, sizeof(char) * (nn + 1));
            (*size)++;
        }
        return;
    }

    s[nn] = '(';
    Recursion(n - 1, s, nn + 1, ss, size);
    s[nn] = ')';
    Recursion(n - 1, s, nn + 1, ss, size);
    return;
}

void Backtrack(int n, char *s, int left, int right, char **ss, int *size)
{
    if (strlen(s) == 2 * n)
    {
        s[2 * n] = '\0';
        memcpy(ss[*size], s, sizeof(char) * (2 * n + 1));
        (*size)++;
        return;
    }

    if (left < n)
    {
        s[left + right] = '(';
        Backtrack(n, s, left + 1, right, ss, size);
    }

    if (right < n)
    {
        s[left + right] = '(';
        Backtrack(n, s, left, right + 1, ss, size);
    }
}

char **generateParenthesis(int n, int *returnSize)
{
    *returnSize = 0;
    if (n < 0)
    {
        return NULL;
    }
    int size = 1;
    for (int i = 1; i <= n; i++)
    {
        size *= i;
    }

    char **ret = (char **)malloc(sizeof(char *) * size);
    for (int i = 0; i < size; i++)
    {
        ret[i] = (char *)malloc(sizeof(char) * (2 * n + 1));
    }
    char *s = (char *)malloc(sizeof(char) * (2 * n + 1));
    Recursion(2 * n, s, 0, ret, returnSize);

    Backtrack(n, s, 0, 0, ret, 0);

    return ret;
}
