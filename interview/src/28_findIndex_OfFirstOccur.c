#include "base_def.h"
#include "include.h"

/*
给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。

示例 1：
输入：haystack = "sadbutsad", needle = "sad"
输出：0
解释："sad" 在下标 0 和 6 处匹配。
第一个匹配项的下标是 0 ，所以返回0。

示例 2：
输入：haystack = "leetcode", needle = "leeto"
输出：-1
解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
*/

int strStr(char* haystack, char* needle)
{
    char *p = strstr(haystack, needle);
    if (p) {
        return p - haystack;
    } else {
        return -1;
    }
} 

void func28(void)
{
    char *haystack = "hello world";
    char *needle = "wor";
    int ret = strStr(haystack, needle);
    printf("%d\r\n", ret);
}