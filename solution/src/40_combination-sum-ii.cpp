/* 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]
通过次数52,014提交次数84,957

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

#include "solution.h"

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void Backtrack(int *candidates, int candidatesSize, int index, int target, int **ret, int *returnSize, int *retColSizes, int *pBuff, int indexOfBuff)
{
    if (0 == target)
    {
        memcpy(ret[*returnSize], pBuff, indexOfBuff * sizeof(int));
        retColSizes[*returnSize] = indexOfBuff;
        (*returnSize)++;
        return;
    }
    else if (target < 0)
    {
        return;
    }
    printf("%d %d %d %d\r\n", index, target, indexOfBuff, *returnSize);
    for (int i = index; i < candidatesSize; i++)
    {
        if (i > index && candidates[i - 1] == candidates[i])
        {
            continue;
        }
        pBuff[indexOfBuff] = candidates[i];
        Backtrack(candidates, candidatesSize, i + 1, target - candidates[i], ret, returnSize, retColSizes, pBuff, indexOfBuff + 1);
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **combinationSum2(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;
    if (candidatesSize <= 0)
    {
        return NULL;
    }
    qsort(candidates, candidatesSize, sizeof(int), compare);

    int maxSize = 1000;
    int colMaxSize = target / candidates[0] + 1;
    int **ret = (int **)malloc(sizeof(int *) * maxSize);
    for (int i = 0; i < maxSize; i++)
    {
        ret[i] = (int *)malloc(sizeof(int) * colMaxSize);
    }
    int *retColSizes = (int *)malloc(sizeof(int *) * maxSize);
    memset(retColSizes, 0x0, sizeof(int) * maxSize);
    *returnColumnSizes = retColSizes;
    int *pBuff = (int *)malloc(sizeof(int) * colMaxSize);

    Backtrack(candidates, candidatesSize, 0, target, ret, returnSize, retColSizes, pBuff, 0);

    return ret;
}
