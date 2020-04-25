#include "test.h"

TEST(test_searchRange, test_searchRange001)
{
    int nums[] = {1, 3, 5, 6};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 5;
    int expect = 2;
    int ret = searchInsert(nums, numsSize, target);
    ASSERT_EQ(expect, ret);
}

TEST(test_searchRange, test_searchRange002)
{
    int nums[] = {1, 3, 5, 6};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 7;
    int expect = 4;
    int ret = searchInsert(nums, numsSize, target);
    ASSERT_EQ(expect, ret);
}

TEST(test_searchRange, test_searchRange003)
{
    int nums[] = {1, 3, 5, 6};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 0;
    int expect = 0;
    int ret = searchInsert(nums, numsSize, target);
    ASSERT_EQ(expect, ret);
}

TEST(test_searchRange, test_searchRange04)
{
    int nums[] = {};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 5;
    int expect = 0;
    int ret = searchInsert(nums, numsSize, target);
    ASSERT_EQ(expect, ret);
}
