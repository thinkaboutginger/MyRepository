#include "base_def.h"
#include "include.h"

/*
给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
如果可以，返回 true ；否则返回 false 。magazine 中的每个字符只能在 ransomNote 中使用一次。

示例 1：
输入：ransomNote = "a", magazine = "b"
输出：false

示例 2：
输入：ransomNote = "aa", magazine = "ab"
输出：false

示例 3：
输入：ransomNote = "aa", magazine = "aab"
输出：true
 
提示：ransomNote 和 magazine 由小写英文字母组成
*/

BOOLEAN canConstruct(char* ransomNote, char* magazine)
{
    int num[26] = {0};
    for (int i = 0; i < strlen(magazine); i++) {
        int index = magazine[i] - 'a';
        num[index]++;
    }
    for (int i = 0; i < strlen(ransomNote); i++) {
        int index = ransomNote[i] - 'a';
        num[index]--;
        if (num[index] < 0) {
            return FALSE;
        }
    }
    return TRUE;
}

void func383(void)
{
    char *random = "ab";
    char *magzine = "aab";
    BOOLEAN ret = canConstruct(random, magzine);
    printf("ret = %d\r\n", ret);
}