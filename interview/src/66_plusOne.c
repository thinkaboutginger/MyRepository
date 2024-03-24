#include "base_def.h"
#include "include.h"

/*
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1：
输入：digits = [1,2,3]
输出：[1,2,4]
解释：输入数组表示数字 123。

示例 2：
输入：digits = [4,3,2,1]
输出：[4,3,2,2]
解释：输入数组表示数字 4321。

示例 3：
输入：digits = [0]
输出：[1]
*/

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int num = 1;
    for (int i = digitsSize - 1; i >= 0; i--) {
        digits[i] = (digits[i] + num) % 10;
        if (digits[i] != 0) {
            num = 0;
        }
    }
    if (digits[0] == 0) {
        int *ret = (int *)malloc(sizeof(int) * (digitsSize + 1));
        ret[0] = 1;
        for (int i = 1; i <= digitsSize; i++) {
            ret[i] = digits[i - 1];
        }
        *returnSize = digitsSize + 1;
        return ret;
    } else {
        *returnSize = digitsSize;
        return digits;
    }
}

void func66(void)
{
    int a[7] = {2, 2, 1, 1, 1, 2, 2};
    int *ret = (int *)malloc(sizeof(int) * 7);
    int tmp = 0;
    ret = plusOne(a, 7, &tmp);
    for (int i = 0; i < 7; i++) {
        printf("%d ", ret[i]);
    }
}
