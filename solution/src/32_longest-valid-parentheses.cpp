/* 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1:

输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"
示例 2:

输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"
通过次数51,784提交次数171,869

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

#include "solution.h"

bool isValidParentheses(char *s)
{
    int ret = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '(')
        {
            ret++;
        }
        else if (s[i] == ')')
        {
            ret--;
        }
        if (ret < 0)
        {
            return false;
        }
    }
    if (ret != 0)
    {
        return false;
    }
    return true;
}

int longestValidParentheses(char *s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (isValidParentheses(&s[i]))
        {
        }
    }
}

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

bool binarySearch(int *nums, int left, int right, int target, int *pos)
{
    if (left > right)
    {
        *pos = left;
        return false;
    }
    int mid = (right + left) / 2;
    if (nums[mid] > target)
    {
        return binarySearch(nums, left, mid - 1, target, pos);
    }
    else if (nums[mid] < target)
    {
        return binarySearch(nums, mid + 1, right, target, pos);
    }
    *pos = mid;
    return true;
}

int searchInsert(int *nums, int numsSize, int target)
{
    int pos = 0;
    int isInside = 0;
    isInside = binarySearch(nums, 0, numsSize - 1, target, &pos);
    // if (isInside) {
    //     return pos;
    // } else {

    // }
    return pos;
}
