/* 
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include "solution.h"

bool btreeSearchLeft(int *nums, int p, int q, int target, int *pos)
{
    if (p == q)
    {
        if (nums[p] == target)
        {
            *pos = p;
            return true;
        }
        return false;
    }
    int mid = (q + p) / 2;
    if (nums[mid] >= target)
    {
        return btreeSearchLeft(nums, p, mid, target, pos);
    }
    else
    {
        return btreeSearchLeft(nums, mid + 1, q, target, pos);
    }
}

bool btreeSearchRight(int *nums, int p, int q, int target, int *pos)
{
    if (p == q)
    {
        if (nums[p] == target)
        {
            *pos = p;
            return true;
        }
        return false;
    }
    int mid = (q + p) / 2 + 1;
    if (nums[mid] <= target)
    {
        return btreeSearchRight(nums, mid, q, target, pos);
    }
    else
    {
        return btreeSearchRight(nums, p, mid - 1, target, pos);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
    if (nums == NULL || returnSize == NULL)
    {
        return NULL;
    }

    int left;
    int right;
    int *ret = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    if (numsSize < 1)
    {
        *returnSize = 2;
        ret[0] = -1;
        ret[1] = -1;
        return ret;
    }
    if (btreeSearchLeft(nums, 0, numsSize - 1, target, &left))
    {
        ret[0] = left;
    }
    else
    {
        ret[0] = -1;
    }
    if (btreeSearchRight(nums, 0, numsSize - 1, target, &right))
    {
        ret[1] = right;
    }
    else
    {
        ret[1] = -1;
    }
    return ret;
}
