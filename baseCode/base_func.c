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

/* *************************************以下为链表相关的定义************************************* */
/* 功能：用一个数组的元素值来初始化链表 */
struct ListNode* initSingleListInt(struct ListNode *head, INT32S *data, INT32U dataLen)
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
    return head;
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