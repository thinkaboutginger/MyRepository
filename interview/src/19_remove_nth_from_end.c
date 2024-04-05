#include "base_def.h"
#include "include.h"

/*
题干：给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int len = 0;
    struct ListNode* p = head;
    while (p) {
        len++;
        p = p->next;
    }
    if (n > len) {
        return NULL;
    }
    if (n == len) {
        return head->next;
    }
    p = head;
    while (p) {
        len--;
        if (len == n) {
            p->next = p->next->next;
        }
        p = p->next;
    }
    return head;
}

void func19(void)
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    INT32S data[] = {1,2,3,4,5};
    INT32U dataLen = ARR_SIZE(data);
    initSingleListInt(head, data, dataLen);
    struct ListNode* ret = (struct ListNode *)malloc(sizeof(struct ListNode));
    ret = removeNthFromEnd(head, 2);
    printSingleListInt(ret);
}