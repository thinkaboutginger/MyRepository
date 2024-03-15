#include "base_def.h"
#include "misc.h"

/*
给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。

示例 1:
输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右轮转 1 步: [7,1,2,3,4,5,6]
向右轮转 2 步: [6,7,1,2,3,4,5]
向右轮转 3 步: [5,6,7,1,2,3,4]

示例 2:
输入：nums = [-1,-100,3,99], k = 2
输出：[3,99,-1,-100]
解释: 
向右轮转 1 步: [99,-1,-100,3]
向右轮转 2 步: [3,99,-1,-100] 
*/

void rotateBase(int* nums, int numsSize, int k) {
    int buf[numsSize];
    int delta = k % numsSize;
    for (int i = 0; i < numsSize; i++) {
        buf[i] = nums[(i - delta + numsSize) % numsSize];
    }
    for (int i = 0; i < numsSize; i++) {
        nums[i] = buf[i];
    }
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverse(int *data, int dataLen)
{
    int i = 0, j = dataLen - 1;
    while (j - i >= 1) {
        swap(&data[i], &data[j]);
        i++;
        j--;
    }
}

void rotateAdvanced(int* nums, int numsSize, int k) {
    int delta = k % numsSize;
    reverse(nums, numsSize);
    reverse(nums, delta);
    reverse(&nums[delta], numsSize - delta);
}

void func189(void)
{
    INT32S nums[] = {1, 2, 3, 4, 5, 6, 7};
    rotateAdvanced(nums, ARR_SIZE(nums), 3);
    for (INT16U i = 0; i < ARR_SIZE(nums); i++) {
        printf("%d ", nums[i]);
    }
}