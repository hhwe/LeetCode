/* 给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。

 

示例:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

输出:  [1,2,4,7,5,3,6,8,9]

解释:

 

说明:

给定矩阵中的元素总数不会超过 100000 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/diagonal-traverse
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

// #include "solution.h"
#include "solution.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findDiagonalOrder(int **matrix, int matrixSize, int *matrixColSize, int *returnSize)
{
    if (matrixSize <= 0 || *matrixColSize <= 0 || matrix == NULL)
    {
        return NULL;
    }

    int row = 0;
    int col = 0;

    int dir = 0;
    *returnSize = matrixSize * (*matrixColSize);
    int *ret = (int *)malloc(sizeof(int) * *returnSize);
    int index = 0;
    while (row != matrixSize - 1 || col != *matrixColSize - 1)
    {
        if (dir == 0)
        {
            ret[index++] = matrix[row][col];
            row--;
            col++;

            if (row < 0 && col <= *matrixColSize - 1)
            {
                row = 0;
                dir = 1;
            }
            else if (col > *matrixColSize - 1)
            {
                row += 2;
                col = *matrixColSize - 1;
                dir = 1;
            }
        }
        else
        {
            ret[index++] = matrix[row][col];
            row++;
            col--;

            if (col < 0 && row <= matrixSize - 1)
            {
                col = 0;
                dir = 0;
            }
            else if (row > matrixSize - 1)
            {
                col += 2;
                row = matrixSize - 1;
                dir = 0;
            }
        }
    }
    ret[index] = matrix[row][col];
    return ret;
}
