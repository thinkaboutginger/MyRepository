#include "base_def.h"
#include "misc.h"

/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1
*/

int singleNumber(int* nums, int numsSize)
{
    int n = nums[0];
    for (int i = 1; i < numsSize; i++) {
        n ^= nums[i];
    }
    return n;
}

void func136(void)
{
    INT32S nums[5] = {4, 1, 2, 1, 4};
    INT32S ret = singleNumber(nums, (sizeof(nums) / sizeof(INT32S)));
    printf("ret = %d\r\n", ret);
}