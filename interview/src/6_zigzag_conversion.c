#include "base_def.h"
#include "include.h"

/*
题干：
将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
请你实现这个将字符串进行指定行数变换的函数：string convert(string s, int numRows);

示例 1：
输入：s = "PAYPALISHIRING", numRows = 3
输出："PAHNAPLSIIGYIR"

示例 2：
输入：s = "PAYPALISHIRING", numRows = 4
输出："PINALSIGYAHRPI"
解释：
P     I    N
A   L S  I G
Y A   H R
P     I

示例 3：
输入：s = "A", numRows = 1
输出："A"
*/

char* convert(char* s, int numRows) {
    if (numRows == 1) {
        return s;
    }
    int len = strlen(s);
    int k = 0;
    int delta1 = 2 * numRows - 2;
    int delta2 = 0;
    char *ret = (char*)malloc(sizeof(char) * (len + 1));
    for (int row = 0; row < numRows; row++) {
        int delta = delta2;
        int i = row;
        while (i < len && delta1 >= 0 && delta2 >= 0) {
            delta = (delta == delta2 ? delta1 : delta2);
            if (delta != 0) {
                ret[k] = s[i];
                i += delta;
                k++;
            }
        }
        delta1 -= 2;
        delta2 += 2;
    }
    ret[len] = '\0';
    return ret;
}

char* convertMatrix(char* s, int numRows) {
    if (numRows == 1) {
        return s;
    }
    int len = strlen(s);
    int numColumns = len / 2 + 1;
    char *ret = (char*)malloc(sizeof(char) * (len + 1));
    int num[numRows][numColumns];
    memset(num, 0, sizeof(num));
    int row = 0;
    int column = 0;
    int isDown = TRUE;
    for (int i = 0; i < len; i++) {
        num[row][column] = s[i];
        if (isDown == TRUE) {
            row++;
        } else {
            row--;
            column++;
        }
        if (row == numRows - 1) {
            isDown = FALSE;
        }
        if (row == 0) {
            isDown = TRUE;
        }
    }
    int k = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            if (num[i][j] != 0) {
                ret[k] = num[i][j];
                k++;
            }
        }
    }   
    ret[len] = '\0';
    return ret;
}

void func6(void)
{
    char s[] = "PAYPALISHIRING";
    int len = strlen(s);
    char *ret = convertMatrix(s, 4);
    printf("%s", ret);
}