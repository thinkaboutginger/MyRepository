#include "base_def.h"
#include "code.h"

/*
请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数（类似 C/C++ 中的 atoi 函数）。

函数 myAtoi(string s) 的算法如下：
读入字符串并丢弃无用的前导空格
检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
如果整数数超过 32 位有符号整数范围 [−2^31,  2^31 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −2^31 的整数应该被固定为 −2^31 ，大于 2^31 − 1 的整数应该被固定为 2^31 − 1 。
返回整数作为最终结果。

注意：
本题中的空白字符只包括空格字符 ' ' 。
除前导空格或数字后的其余字符串外，请勿忽略 任何其他字符。
 

示例 1：
输入：s = "42"
输出：42
解析得到整数 42 。
由于 "42" 在范围 [-2^31, 2^31 - 1] 内，最终结果为 42 。

示例 2：
输入：s = "   -42"
输出：-42
解析得到整数 -42 。
由于 "-42" 在范围 [-2^31, 2^31 - 1] 内，最终结果为 -42 。

示例 3：
输入：s = "4193 with words"
输出：4193
解析得到整数 4193 。
由于 "4193" 在范围 [-2^31, 2^31 - 1] 内，最终结果为 4193 。
*/

#define DELTA '0'
enum {
    STATE_START = 0,
    STATE_SIGNED,
    STATE_NUMBER,
    STATE_END,
    STATE_RET,
};

int sig = 1;
int GetNumber(char *s, int start, int end)
{
    double ret = 0.0;
    for (int i = start; i < end; i++) {
        int num = s[i] - DELTA;
        if (sig == 1 && num > INT_MAX - ret * 10) {
            return INT_MAX;
        }
        if (sig == -1 && num > INT_MAX - ret * 10 + 1) {
            return INT_MIN;
        }
        ret = ret * 10 + num;
    }
    return (ret * sig);
}

int start = 0;
int end = 0;
int myAtoi(char* s)
{
    int state = STATE_START;
    int index = 0;
    int ret = 0;
    while (state != STATE_RET) {
        switch (state) {
            case STATE_START:
                if (s[index] == ' ') {
                    index++;
                } else {
                    state = STATE_SIGNED;
                }
                break;
            case STATE_SIGNED:
                if (s[index] == '-') {
                    sig = -1;
                    index++;
                } else if (s[index] == '+') {
                    index++;
                }
                start = index;
                state = STATE_NUMBER;
                break;
            case STATE_NUMBER:
                if (s[index] >= '0' && s[index] <= '9') {
                    index++;
                } else {
                    end = index;
                    state = STATE_END;
                }
                break;
            case STATE_END:
                ret = GetNumber(s, start, index);
                state = STATE_RET;
                break;
        }
    }
    return ret;
}

void func8(void)
{
    char s[] = "4193 with words";
    int ret = myAtoi(s);
    printf("%d ", ret);
}