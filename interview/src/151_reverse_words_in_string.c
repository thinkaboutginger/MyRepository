#include "base_def.h"
#include "include.h"

/*
题干：
给你一个字符串 s ，请你反转字符串中 单词 的顺序。
单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。

示例 1：
输入：s = "the sky is blue"
输出："blue is sky the"

示例 2：
输入：s = "  hello world  "
输出："world hello"
解释：反转后的字符串中不能存在前导空格和尾随空格。

示例 3：
输入：s = "a good   example"
输出："example good a"
解释：如果两个单词间有多余的空格，反转后的字符串需要将单词间的空格减少到仅有一个。
 
提示：
1 <= s.length <= 104
s 包含英文大小写字母、数字和空格 ' '
s 中 至少存在一个 单词
*/

char *ret = NULL;
int word_head = 0; /* 单词头指针 */
int word_tail = 0; /* 单词尾指针 */
int idx = 0;

int FindWord(char* s) {
    /* 寻找单词的最后一个字母 */
    while (s[word_tail] == ' ') {
        if (word_tail >= 0) {
            word_tail--;
            if (word_tail < 0) {
                return -1;
            }
        }
    }
    word_head = word_tail;
    /* 寻找单词的第一个字母 */
    while (s[word_head] != ' ' && word_head > 0) {
        word_head--;
    }
    return 0;
}

void CopyWord(char *s, char *ret, int *idx, int start, int len) {
    for (int i = start; i <= len; i++) {
        ret[*idx] = s[word_head + i];
        (*idx)++;
    }
    ret[*idx] = ' ';
    (*idx)++;
}

char* reverseWords(char* s) {
    /* 从后往前找单词 */
    int len = strlen(s);
    if (len == 1) {
        return s;
    }
    ret = (char *)malloc(sizeof(char) * (len + 1));
    word_head = len - 1;
    word_tail = len - 1;
    while(word_head > 0) {
        if(FindWord(s) == -1) {
            ret[idx - 1] = '\0';
            return ret;
        }
        if (s[word_head] != ' ') {
            CopyWord(s, ret, &idx, 0, word_tail - word_head);
        } else {
            CopyWord(s, ret, &idx, 1, word_tail - word_head);
        }
        word_tail = word_head;
    }
    ret[idx - 1] = '\0';
    return ret;
}

void func151(void)
{
    char s[] = "  hello world  ";
    ret = reverseWords(s);
    printf("%s\r\n", ret);
}