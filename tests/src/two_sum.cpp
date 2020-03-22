#include "gtest/gtest.h"
#include "solution.h"

TEST(test_two_sum, twoSum001)
{
    int nums[4] = {2, 7, 11, 15};
    int target = 9;
    int numsSize = 4;
    int *result = twoSum(nums, numsSize, target);

    ASSERT_EQ(0, *result);
    ASSERT_EQ(1, *(result + 1));
}
