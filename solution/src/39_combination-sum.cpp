/* 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]
示例 2:

输入: candidates = [2,3,5], target = 8,
所求解集为:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
通过次数83,474提交次数121,310

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum
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
        pBuff[indexOfBuff] = candidates[i];
        Backtrack(candidates, candidatesSize, i, target - candidates[i], ret, returnSize, retColSizes, pBuff, indexOfBuff + 1);
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **combinationSum(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes)
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
