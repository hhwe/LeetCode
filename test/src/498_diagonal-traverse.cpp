#include "test.h"

TEST(test_searchRange, test_searchRange001)
{

    int **a = (int **)malloc(sizeof(int *) * 3);
    int tmp = 1;
    for (int i = 0; i < 3; i++)
    {
        a[i] = (int *)malloc(sizeof(int) * 3);
        for (int j = 0; j < 3; j++)
        {
            a[i][j] = tmp++;
        }
    }
    int returnSize = 0;
    int matrixSize = 3;
    int matrixColSize = 3;
    int expectSize = 9;
    int expect[] = {1, 2, 4, 7, 5, 3, 6, 8, 9};
    int *ret = findDiagonalOrder(a, matrixSize, &matrixColSize, &returnSize);
    ASSERT_EQ(expectSize, returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        ASSERT_EQ(expect[i], ret[i]);
    }
}
