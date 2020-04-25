#pragma once

#ifndef __SOLUTION_H__
#define __SOLUTION_H__

#include "common.h"

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}


struct ListNode
{
    int val;
    struct ListNode *next;
};

int *twoSum(int *nums, int numsSize, int target);
char **generateParenthesis(int n, int *returnSize);
struct ListNode *swapPairs(struct ListNode *head);
int divide(int dividend, int divisor);
int *searchRange(int *nums, int numsSize, int target, int *returnSize);
int *findDiagonalOrder(int **matrix, int matrixSize, int *matrixColSize, int *returnSize);
char *minRemoveToMakeValid(char *s);
int searchInsert(int *nums, int numsSize, int target);
int **combinationSum(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes);
int **combinationSum2(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes);
void rotate(int **matrix, int matrixSize, int *matrixColSize);

#endif
