#include "base_def.h"
#include "include.h"

/*
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。

示例 1：
输入：strs = ["flower","flow","flight"]
输出："fl"

示例 2：
输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。
*/

char* longestCommonPrefix(char** strs, int strsSize) {
    int len = strlen(strs[0]);
    BOOLEAN flag = FALSE;
    for (int i = 0; i < strlen(strs[0]); i++) {
        char c = strs[0][i];
        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] == '\0' || strs[j][i] != c) {
                len = i;
                flag = TRUE;
                break;
            }
        }
        if (flag == TRUE) {
            break;
        }
    }
    strs[0][len] = '\0';
    return strs[0];
}

void func14(void)
{
    char *str[] = {"ab", "ab", "ab"};
    char *ret = longestCommonPrefix(str, 3);
    printf("s = %s\r\n", ret);
}