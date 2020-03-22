/**
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
Note: The returned array must be malloced, assume caller calls free().
*
*/
#include "solution.h"

int *twoSum(int *nums, int numsSize, int target)
{
    int loop = 0;
    int inloop = 0;
    int *result = NULL;
    result = (int *)malloc(2 * sizeof(int));
    memset(result, 0, 2 * sizeof(int));
    printf("numsSize=%d\n", numsSize);
    if (NULL == nums || numsSize == 0)
    {
        return result;
    }
    for (loop = 0; loop < numsSize; loop++)
    {
        for (inloop = loop + 1; inloop < numsSize; inloop++)
        {
            if (*(nums + loop) + *(nums + inloop) == target)
            {
                if (NULL != result)
                {

                    *result = loop;
                    *(result + 1) = inloop;
                }
                return result;
            }
        }
    }
    return result;
}