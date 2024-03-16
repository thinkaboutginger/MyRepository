#include "base_def.h"
#include "include.h"

/*
给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。例如，121 是回文，而 123 不是。

示例 1：
输入：x = 121
输出：true

示例 2：
输入：x = -121
输出：false
解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
*/

#define NUMTOCHAR (1 - '1') /* 取数字1和字符1之间的ASCII码值之差 */

INT32S Itoa(INT32S x, char *s)
{
    INT32S i = 0;
    while (x != 0) {
        INT32S tmp = x % 10;
        s[i] = tmp - NUMTOCHAR;
        x = x / 10;
        i++;
    }
    return i;
}

/* 基础解法：转换成字符串，整一对头尾指针向中间移动 */
BOOLEAN isPalindromeBase(INT32S x)
{
    if (x < 0) {
        return FALSE;
    }
    INT8S s[100];
    INT32S len = Itoa(x, s);
    INT32S i = 0, j = len - 1;
    while(j - i >= 1) {
        if (s[i] != s[j]) {
            return FALSE;
        }
        i++;
        j--;
    }
    return TRUE;
}

/* 进阶解法：采用数学方式。为防止数据溢出，数据类型采用long int */
BOOLEAN isPalindromeAdvance(int x)
{
    if (x < 0) {
        return FALSE;
    }
    long int sum = 0;
    long int n = x;
    while (n != 0) {
        sum = sum * 10 + n % 10;
        n = n / 10;
    }
    if (sum != x) {
        return FALSE;
    }
    return TRUE;
}

void func9(void)
{
    // BOOLEAN ret = isPalindromeBase(10);
    BOOLEAN ret = isPalindromeAdvance(10);
    printf("ret = %d\r\n", ret);
}