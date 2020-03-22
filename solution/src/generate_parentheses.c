#include "solution.h"

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

char **generateParenthesis(int n, int *returnSize)
{
    *returnSize = 0;
    if (n < 0)
    {
        return NULL;
    }
    char **ret = (char **)malloc(sizeof(char *) * n * n);
    for (int i = 0; i < n * n; i++)
    {
        ret[i] = (char *)malloc(sizeof(char) * (2 * n + 1));
    }
    char *s = (char *)malloc(sizeof(char) * (2 * n + 1));
    Recursion(2 * n, s, 0, ret, returnSize);
    return ret;
}
