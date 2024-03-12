#include "base_def.h"
#include "include.h"

/*
给你一个字符串 title ，它由单个空格连接一个或多个单词组成，每个单词都只包含英文字母。请你按以下规则将每个单词的首字母大写 ：
如果单词的长度为 1 或者 2 ，所有字母变成小写。否则，将单词首字母大写，剩余字母变成小写。
请你返回大写后的 title 。

示例 1：
输入：title = "First leTTeR of EACH Word"
输出："First Letter of Each Word"
解释：单词 "of" 长度为 2 ，所以它保持完全小写。其他单词长度都至少为 3 ，所以其他单词首字母大写，剩余字母小写。

示例 2：
输入：title = "i lOve leetcode"
输出："i Love Leetcode"
解释：单词 "i" 长度为 1 ，所以它保留小写。其他单词长度都至少为 3 ，所以其他单词首字母大写，剩余字母小写。
*/

#define DELTA ('A'-'a')

void lowerToUpper(char *c)
{
    if(*c >= 'A' && *c <= 'Z') {
        return;
    } else if (*c >= 'a' && *c <= 'z') {
        *c += DELTA;
    }
}

void upperToLower(char *c)
{
    if(*c >= 'a' && *c <= 'z') {
        return;
    } else if (*c >= 'A' && *c <= 'Z') {
        *c -= DELTA;
    }
}

char* capitalizeTitle(char* title) {
    int j = 0;
    for (int i = 0; i <= strlen(title); i++) {
        if (title[i] == ' ' || title[i] == '\0') {
            if (i - j > 2) {
                lowerToUpper(&title[j]);
            }
            j = i + 1;
        }
        upperToLower(&title[i]);
    }
    return title;
}

void func2129(void)
{
    INT8S title[] = "First of ALL";
    INT8S *ret = capitalizeTitle(title);
    printf("ret = %s\r\n", ret);
}