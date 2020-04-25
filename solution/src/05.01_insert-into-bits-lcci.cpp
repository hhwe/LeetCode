/* 插入。给定两个32位的整数N与M，以及表示比特位置的i与j。编写一种方法，将M插入N，使得M从N的第j位开始，到第i位结束。假定从j位到i位足以容纳M，也即若M = 10 011，那么j和i之间至少可容纳5个位。例如，不可能出现j = 3和i = 2的情况，因为第3位和第2位之间放不下M。

示例1:

 输入：N = 10000000000, M = 10011, i = 2, j = 6
 输出：N = 10001001100
示例2:

 输入： N = 0, M = 11111, i = 0, j = 4
 输出：N = 11111
通过次数1,031提交次数2,143

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/insert-into-bits-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

#include "solution.h"

int insertBits(int N, int M, int i, int j)
{
    int mask = (1 << (j - i + 1)) - (1 << i);
    return (N & ~mask) | M << i;
}

/* 给出 N 名运动员的成绩，找出他们的相对名次并授予前三名对应的奖牌。前三名运动员将会被分别授予 “金牌”，“银牌” 和“ 铜牌”（"Gold Medal", "Silver Medal", "Bronze Medal"）。

(注：分数越高的选手，排名越靠前。)

示例 1:

输入: [5, 4, 3, 2, 1]
输出: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
解释: 前三名运动员的成绩为前三高的，因此将会分别被授予 “金牌”，“银牌”和“铜牌” ("Gold Medal", "Silver Medal" and "Bronze Medal").
余下的两名运动员，我们只需要通过他们的成绩计算将其相对名次即可。
提示:

N 是一个正整数并且不会超过 10000。
所有运动员的成绩都不相同。
通过次数8,507提交次数15,812

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/relative-ranks
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

struct RankNode
{
    int index;
    int data;
};

int compare(const void *a, const void *b)
{
    return ((RankNode *)b)->data - ((RankNode *)a)->data;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **findRelativeRanks(int *nums, int numsSize, int *returnSize)
{
    char *a[3] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
    struct RankNode *bucket = (struct RankNode *)malloc(sizeof(struct RankNode) * numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        bucket[i].index = i;
        bucket[i].data = nums[i];
    }
    qsort(bucket, numsSize, sizeof(struct RankNode), compare);
    char **ret = (char **)malloc(sizeof(char *) * numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        ret[bucket[i].index] = (char *)malloc(sizeof(char) * 15);
        if (i < 3)
        {
            strcpy(ret[bucket[i].index], a[i]);
        }
        else
        {
            sprintf(ret[bucket[i].index], "%d", i + 1);
        }
    }
    *returnSize = numsSize;
    return ret;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", insertBits(1143207437, 1017033, 11, 31));
    return 0;
}
