#include "base_def.h"
#include "include.h"
#include "uthash.h"

typedef struct{
    int key;
    int value;
    UT_hash_handle hh;
} Hash;

Hash *hashTable = NULL;
int ret = 0;

void delete_all(void) {
    Hash *it, *tmp;
    HASH_ITER(hh, hashTable, it, tmp) {
        HASH_DEL(hashTable,it);
        free(it);
    }
}

void insert(int ikey, int value, int size) {
    Hash *it = NULL;
    HASH_FIND_INT(hashTable, &ikey, it);
    if (it == NULL) {
        Hash *tmp = (Hash*)malloc(sizeof(Hash));
        tmp->key = ikey;
        tmp->value = value;
        HASH_ADD_INT(hashTable, key, tmp);
        if (tmp->value > size) {
            ret = tmp->key;
        }
    } else {
        it->value++;
        if (it->value > size) {
            ret = it->key;
        }
    }
}

Hash* find(int num) {
    Hash* it = NULL;
    HASH_FIND_INT(hashTable, &num, it);
    return it;
}

int majorityElement(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        insert(nums[i], 1, (numsSize / 2));
    }
    delete_all();
    return ret;
}

void func169(void)
{
    int a[7] = {2, 2, 1, 1, 1, 2, 2};
    int ret = majorityElement(a, 7);
    printf("ret = %d\r\n", ret);
}