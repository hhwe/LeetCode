#include "test.h"

TEST(test_searchRange, test_searchRange001)
{
    int nums[] = {5, 7, 7, 8, 8, 10};
    int numsSize = 6;
    int target = 8;
    int returnSize;
    int expectSize = 2;
    int expect[] = {2, 4};
    int *ret = searchRange(nums, numsSize, target, &returnSize);
    ASSERT_EQ(expectSize, returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        ASSERT_EQ(expect[i], ret[i]);
    }
}
