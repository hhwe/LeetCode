#include "test.h"

TEST(test_case, test_case001)
{
    int input[][3] = {{1, 2, 3},
                      {4, 5, 6},
                      {7, 8, 9}};
    int output[][3] = {{7, 4, 1},
                       {8, 5, 2},
                       {9, 6, 3}};
    int matrixSize = 3;
    int matrixColSize = 3;
    int **matrix = (int **)malloc(sizeof(int *) * matrixSize);
    for (int i = 0; i < matrixSize; i++)
    {
        matrix[i] = (int *)malloc(sizeof(int) * matrixColSize);
        for (int j = 0; j < matrixColSize; j++)
        {
            matrix[i][j] = input[i][j];
        }
    }
    rotate(matrix, matrixSize, &matrixColSize);
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixColSize; j++)
        {
            ASSERT_EQ(matrix[i][j], output[i][j]);
        }
    }
}

TEST(test_case, test_case002)
{
    int input[][4] = {{5, 1, 9, 11},
                      {2, 4, 8, 10},
                      {13, 3, 6, 7},
                      {15, 14, 12, 16}};
    int output[][4] = {{15, 13, 2, 5},
                       {14, 3, 4, 1},
                       {12, 6, 8, 9},
                       {16, 7, 10, 11}};
    int matrixSize = 4;
    int matrixColSize = 4;
    int **matrix = (int **)malloc(sizeof(int *) * matrixSize);
    for (int i = 0; i < matrixSize; i++)
    {
        matrix[i] = (int *)malloc(sizeof(int) * matrixColSize);
        for (int j = 0; j < matrixColSize; j++)
        {
            matrix[i][j] = input[i][j];
        }
    }
    rotate(matrix, matrixSize, &matrixColSize);
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixColSize; j++)
        {
            ASSERT_EQ(matrix[i][j], output[i][j]);
        }
    }
}
