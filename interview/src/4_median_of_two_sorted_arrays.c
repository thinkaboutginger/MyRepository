#include "base_def.h"
#include "include.h"

/*
题干：
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
算法的时间复杂度应该为 O(log (m+n)) 。

示例 1：
输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2

示例 2：
输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
*/

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int len = nums1Size + nums2Size;
    int middle = len / 2;
    int *ret = (int *)malloc(sizeof(int) * len);
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] <= nums2[j]) {
            ret[k] = nums1[i];
            i++;
        } else {
            ret[k] = nums2[j];
            j++;
        }
        k++;
    }
    while (i < nums1Size) {
        ret[k] = nums1[i];
        i++;
        k++;
    }
    while (j < nums2Size) {
        ret[k] = nums2[j];
        k++;
        j++;
    }
    double num = 0;
    if (len % 2) {
        num = (double)ret[middle];
    } else {
        num = (double)((double)(ret[middle] + ret[middle - 1]) / (double)2);
    }
    return num;
}

void func4(void)
{
    int nums1[] = {1,3};
    int nums2[] = {3,4};
    double ret = findMedianSortedArrays(nums1, ARR_SIZE(nums1), nums2, ARR_SIZE(nums2));
    printf("ret = %.6f", ret);
}