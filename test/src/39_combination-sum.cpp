#include "test.h"

TEST(test_case, test_case001)
{
    int nums[] = {2, 3, 6, 7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 7;
    int returnSize;
    int *returnColumnSizes;
    int expect[][3] = {
        {2, 2, 3},
        {7},
    };
    int expectSize = 2;
    int expectColumnSizes[2] = {3, 1};
    int **ret = combinationSum(nums, numsSize, target, &returnSize, &returnColumnSizes);

    ASSERT_EQ(expectSize, returnSize);
    for (int i = 0; i < expectSize; i++)
    {
        ASSERT_EQ(expectColumnSizes[i], returnColumnSizes[i]);
        // for (int j = 0; j < expectColumnSizes[i]; j++)
        // {
        //     ASSERT_EQ(expect[i][j], ret[i][j]);
        // }
    }
}

TEST(test_case, test_case002)
{
    int nums[] = {2, 3, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 8;
    int returnSize;
    int *returnColumnSizes;
    int expect[][4] = {{2, 2, 2, 2}, {2, 3, 3}, {3, 5}};
    int expectSize = 3;
    int expectColumnSizes[expectSize] = {4, 3, 2};
    int **ret = combinationSum(nums, numsSize, target, &returnSize, &returnColumnSizes);

    ASSERT_EQ(expectSize, returnSize);
    for (int i = 0; i < expectSize; i++)
    {
        ASSERT_EQ(expectColumnSizes[i], returnColumnSizes[i]);
        // for (int j = 0; j < expectColumnSizes[i]; j++)
        // {
        //     ASSERT_EQ(expect[i][j], ret[i][j]);
        // }
    }
}
