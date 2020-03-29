#pragma once

#ifndef __SOLUTION_H__
#define __SOLUTION_H__

#include "common.h"

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

#endif