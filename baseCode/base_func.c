#include "base_def.h"

void SWAP_INT(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void SWAP_CHAR(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

/* *************************************以下为qsort相关的定义************************************* */
INT32S cmpfuncInt(const void * a, const void * b)
{
    /* 基础写法：用减法比较，但可能产生溢出 */
    // return (*(int*)a - *(int*)b);

    /* 改进写法：直接比较 */
    const int *aa = (int*)a;
    const int *bb = (int*)b;
    if (*aa < *bb) {
        return -1;
    } else if (*aa > *bb) {
        return 1;
    } else {
        return 0;
    }
}

INT32S cmpfuncChar(const void * a, const void * b)
{
    char *aa = (char*)a;
    char *bb = (char*)b;
    if ((int)(*aa) < (int)(*bb)) {
        return -1;
    } else if (*aa > *bb) {
        return 1;
    } else {
        return 0;
    }
}

INT32S qsortInt(INT32S *num, INT32S numsSize)
{
    qsort(num, numsSize, sizeof(INT32S), cmpfuncInt);
}

INT32S qsortChar(INT8S *num, INT32S numsSize)
{
    qsort(num, numsSize, sizeof(INT8S), cmpfuncChar);
}

/* *************************************以下为链表相关的函数************************************* */
/* 功能：用一个数组的元素值来初始化链表 */
void initSingleListInt(struct ListNode *head, INT32S *data, INT32U dataLen)
{
    struct ListNode *tail = head;
    head->val = data[0];
    head->next = NULL;
    for (int i = 1; i < dataLen; i++) {
        struct ListNode *tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
        tmp->val = data[i];
        tmp->next = NULL;
        tail->next = tmp;
        tail = tail->next;
    }
}

/* 功能：打印某个链表的value值 */
void printSingleListInt(struct ListNode *list)
{
    struct ListNode *p = list;
    while(p) {
        printf("%d ", p->val);
        p = p->next;
    }
}