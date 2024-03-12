#include "base_def.h"
#include "include.h"

/*
颠倒给定的 32 位无符号整数的二进制位。

示例 1：
输入：n = 00000010100101000001111010011100
输出：964176192 (00111001011110000010100101000000)

示例 2：
输入：n = 11111111111111111111111111111101
输出：3221225471 (10111111111111111111111111111111)
*/

INT32U reverseBits(INT32U n) {
    INT32U ret = 0;
    for (int i = 0; i < 32; i++) {
        INT32U tmp = (INT32U)(n & 0x0001);
        ret = (ret << 1) + tmp;
        n = n >> 1;
    }
    return ret;
}

void func190(void)
{
    INT32U ret = reverseBits(0b00000010100101000001111010011100);
    printf("ret = %d\r\n", ret);
}