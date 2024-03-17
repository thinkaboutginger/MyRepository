#include "base_def.h"
#include "hash.h"
#include "uthash.h"

/*
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。

示例 1：
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

示例 2：
输入：nums = [3,2,4], target = 6
输出：[1,2]

示例 3：
输入：nums = [3,3], target = 6
输出：[0,1]
*/

typedef struct hashTable {
    int key;
    int val;
    UT_hash_handle hh; /* 虽然没用到但必须要写上 */
}Hash;

Hash* hashtable = NULL; /* 初始化为空表，从 i=0 开始依次查找 target-nums[i]，没找到则插入nums[i]，找到则返回 */

Hash* find(int ikey) {
    Hash* tmp;
    HASH_FIND_INT(hashtable, &ikey, tmp); /* 用tmp指向查找到的对象 */
    return tmp;
}

void insert(int ikey, int ival) {
    Hash* it = find(ikey);
    if (it == NULL) { /* 没找到则重新插入一对键-值 */
        Hash* tmp = malloc(sizeof(Hash));
        tmp->key = ikey;
        tmp->val = ival;
        HASH_ADD_INT(hashtable, key, tmp); /* key是插入的tmp的名字 */
    } else { /* 找到则直接插入值 */
        it->val = ival;
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for (int i = 0; i < numsSize; i++) {
        Hash* it = find(target - nums[i]); /* key：数组元素值 value：数组下标 */
        if (it != NULL) {
            int* ret = malloc(sizeof(int) * 2);
            ret[0] = it->val, ret[1] = i; /* 找到则返回i与查找对象的数组下标 */
            *returnSize = 2;
            return ret;
        }
        insert(nums[i], i); /* 没找到则插入当前遍历的值与下标 */
    }
    *returnSize = 0;
    return NULL;
}

void func1(void)
{
    INT32S nums[4] = {2, 7, 11, 15};
    INT32S retSize = 2;
    INT32S* ret = malloc(sizeof(int) * retSize);
    ret = twoSum(nums, ARR_SIZE(nums), 9, &retSize);
    for (int i = 0; i < retSize; i++) {
        printf("%d ", ret[i]);
    }
}