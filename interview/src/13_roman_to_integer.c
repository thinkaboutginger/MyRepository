#include "base_def.h"
#include "include.h"

/*  
题干：
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1 。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。
数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。
这个特殊的规则只适用于以下六种情况：
I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。

示例 1:
输入: s = "LVIII"
输出: 58
解释: L = 50, V= 5, III = 3.

示例 2:
输入: s = "MCMXCIV"
输出: 1994
解释: M = 1000, CM = 900, XC = 90, IV = 4.

提示：
1 <= s.length <= 15
s 仅含字符 ('I', 'V', 'X', 'L', 'C', 'D', 'M')
题目数据保证 s 是一个有效的罗马数字，且表示整数在范围 [1, 3999] 内
题目所给测试用例皆符合罗马数字书写规则，不会出现跨位等情况。
IL 和 IM 这样的例子并不符合题目要求，49 应该写作 XLIX，999 应该写作 CMXCIX 。
*/

typedef struct {
    char *str;
    int strlen;
    int val;
} Value;

Value array[13] = {
    {"M", 1, 1000},
    {"CM", 2, 900},
    {"D", 1, 500},
    {"CD", 2, 400},
    {"C", 1, 100},
    {"XC", 2, 90},
    {"L", 1, 50},
    {"XL", 2, 40},
    {"X", 1, 10},
    {"IX",2, 9},
    {"V", 1, 5},
    {"IV", 2, 4},
    {"I", 1, 1}
};

int romanToInt(char* s) {
    int ret = 0;
    int j = 0;
    while (j < strlen(s)) {
        for (int i = 0; i < 13; i++) {
            char *p = strstr(&s[j], array[i].str);
            if (p && p - s == j) {
                j += array[i].strlen;
                ret += array[i].val;
                break;
            }
        }
    }
    return ret;
}

int romanToInt2(char* s) {
    int array[26] = {0};
    int len = strlen(s);
    array['M' - 'A'] = 1000;
    array['D' - 'A'] = 500;
    array['C' - 'A'] = 100;
    array['L' - 'A'] = 50;
    array['X' - 'A'] = 10;
    array['V' - 'A'] = 5;
    array['I' - 'A'] = 1;
    int ret = 0;
    for (int i = 0; i < len - 1; i++) {
        if (array[s[i] - 'A'] < array[s[i + 1] - 'A']) {
            ret -= array[s[i] - 'A'];
        } else {
            ret += array[s[i] - 'A'];
        }
    }
    ret += array[s[len - 1] - 'A'];
    return ret;
}

void func13(void)
{
    char *s = "MCMXCIV";
    int ret = romanToInt2(s);
    printf("ret = %d", ret);
}