/* 给定一个大小为 n 的数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。

说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1)。

示例 1:

输入: [3,2,3]
输出: [3]
示例 2:

输入: [1,1,1,3,3,2,2,2]
输出: [1,2]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/majority-element-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

#include "solution.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *majorityElement(int *nums, int numsSize, int *returnSize)
{
    int *ret = (int *)malloc(sizeof(int) * (numsSize / 3));
    *returnSize = 0;
    
    for (int i = 0; i < numsSize; i++)
    {
        nums[i];
    }
}
