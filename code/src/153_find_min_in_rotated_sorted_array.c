#include "base_def.h"
#include "code.h"

/*
题干：
已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0,1,2,4,5,6,7] 在变化后可能得到：
若旋转 4 次，则可以得到 [4,5,6,7,0,1,2]
若旋转 7 次，则可以得到 [0,1,2,4,5,6,7]
给你一个元素值 互不相同 的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。
你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。

示例 1：
输入：nums = [3,4,5,1,2]
输出：1
解释：原数组为 [1,2,3,4,5] ，旋转 3 次得到输入数组。

示例 2：
输入：nums = [4,5,6,7,0,1,2]
输出：0
解释：原数组为 [0,1,2,4,5,6,7] ，旋转 3 次得到输入数组。

提示：
nums 中的所有整数 互不相同
nums 原来是一个升序排序的数组，并进行了 1 至 n 次旋转
*/

int findMin(int* nums, int numsSize) {
    int low = 0;
    int high = numsSize - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] < nums[high]) {
            high = mid;
        } else if (nums[mid] > nums[high]) {
            low = mid + 1;
        } else {
            high--;
        }
    }
    return nums[low];
}

void func153(void) {
    int nums[] = {3, 4, 5, 1, 2};
    int numsSize = ARR_SIZE(nums);
    int min = findMin(nums, numsSize);
    printf("min = %d\r\n", min);
}