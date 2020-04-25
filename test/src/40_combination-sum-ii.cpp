#include "test.h"

TEST(test_case, test_case001)
{
    int nums[] = {10, 1, 2, 7, 6, 1, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 8;
    int returnSize;
    int *returnColumnSizes;
    int expect[][3] = {
        {1, 7},
        {1, 2, 5},
        {2, 6},
        {1, 1, 6},
    };
    int expectSize = 4;
    int expectColumnSizes[4] = {2, 3, 2, 3};
    int **ret = combinationSum2(nums, numsSize, target, &returnSize, &returnColumnSizes);

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

// TEST(test_case, test_case002)
// {
//     int nums[] = {2, 5, 2, 1, 2};
//     int numsSize = sizeof(nums) / sizeof(nums[0]);
//     int target = 5;
//     int returnSize;
//     int *returnColumnSizes;
//     int expect[][4] = {{1, 2, 2}, {5}};
//     int expectSize = 2;
//     int expectColumnSizes[expectSize] = {3, 1};
//     int **ret = combinationSum2(nums, numsSize, target, &returnSize, &returnColumnSizes);

//     ASSERT_EQ(expectSize, returnSize);
//     for (int i = 0; i < expectSize; i++)
//     {
//         ASSERT_EQ(expectColumnSizes[i], returnColumnSizes[i]);
//         // for (int j = 0; j < expectColumnSizes[i]; j++)
//         // {
//         //     ASSERT_EQ(expect[i][j], ret[i][j]);
//         // }
//     }
// }
