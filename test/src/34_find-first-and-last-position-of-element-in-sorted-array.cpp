#include "test.h"

TEST(test_searchRange, test_searchRange001)
{
    int nums[] = {5, 7, 7, 8, 8, 10};
    int numsSize = 6;
    int target = 8;
    int returnSize;
    int expectSize = 2;
    int expect[] = {3, 4};
    int *ret = searchRange(nums, numsSize, target, &returnSize);
    ASSERT_EQ(expectSize, returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        ASSERT_EQ(expect[i], ret[i]);
    }
}

TEST(test_searchRange, test_searchRange002)
{
    int nums[] = {5, 7, 7, 8, 8, 10, 10, 10};
    int numsSize = 8;
    int target = 10;
    int returnSize;
    int expectSize = 2;
    int expect[] = {5, 7};
    int *ret = searchRange(nums, numsSize, target, &returnSize);
    ASSERT_EQ(expectSize, returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        ASSERT_EQ(expect[i], ret[i]);
    }
}

TEST(test_searchRange, test_searchRange003)
{
    int nums[] = {1, 1, 1, 1, 1, 1};
    int numsSize = 6;
    int target = 1;
    int returnSize;
    int expectSize = 2;
    int expect[] = {0, 5};
    int *ret = searchRange(nums, numsSize, target, &returnSize);
    ASSERT_EQ(expectSize, returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        ASSERT_EQ(expect[i], ret[i]);
    }
}

TEST(test_searchRange, test_searchRange004)
{
    int nums[] = {1, 2, 3, 4, 5, 6};
    int numsSize = 6;
    int target = 10;
    int returnSize;
    int expectSize = 2;
    int expect[] = {-1, -1};
    int *ret = searchRange(nums, numsSize, target, &returnSize);
    ASSERT_EQ(expectSize, returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        ASSERT_EQ(expect[i], ret[i]);
    }
}

TEST(test_searchRange, test_searchRange005)
{
    int nums[] = {1, 2, 3, 4, 5, 6};
    int numsSize = 6;
    int target = 3;
    int returnSize;
    int expectSize = 2;
    int expect[] = {2, 2};
    int *ret = searchRange(nums, numsSize, target, &returnSize);
    ASSERT_EQ(expectSize, returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        ASSERT_EQ(expect[i], ret[i]);
    }
}

TEST(test_searchRange, test_searchRange006)
{
    int nums[] = {};
    int numsSize = 0;
    int target = 0;
    int returnSize;
    int expectSize = 2;
    int expect[] = {-1, -1};
    int *ret = searchRange(nums, numsSize, target, &returnSize);
    ASSERT_EQ(expectSize, returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        ASSERT_EQ(expect[i], ret[i]);
    }
}

TEST(test_searchRange, test_searchRange007)
{
    int nums[] = {1};
    int numsSize = 1;
    int target = 1;
    int returnSize;
    int expectSize = 2;
    int expect[] = {0, 0};
    int *ret = searchRange(nums, numsSize, target, &returnSize);
    ASSERT_EQ(expectSize, returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        ASSERT_EQ(expect[i], ret[i]);
    }
}