#include "base_def.h"
#include "include.h"

/*
题干：
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例 1：
输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
示例 2：
输入：l1 = [], l2 = []
输出：[]
示例 3：
输入：l1 = [], l2 = [0]
输出：[0]
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void insert(struct ListNode* head, int value) {
    struct ListNode *p = head;
    while (p->next) {
        p = p->next;
    }
    struct ListNode *tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
    tmp->val = value;
    tmp->next = NULL;
    p->next = tmp;
    p = p->next;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* retHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    retHead->val = 0;
    retHead->next = NULL;
    while (list1 && list2) {
        if (list1->val < list2->val) {
            insert(retHead, list1->val);
            list1 = list1->next;
        } else {
            insert(retHead, list2->val);
            list2 = list2->next;
        }
    }
    while(list1) {
        insert(retHead, list1->val);
        list1 = list1->next;
    }
    while(list2) {
        insert(retHead, list2->val);
        list2 = list2->next;
    }
    return retHead->next;
}

void func21(void)
{
    struct ListNode* list1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* list2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    INT32S l1[] = {1, 2, 4};
    INT32S l2[] = {1, 3, 4};
    initSingleListInt(list1, l1, ARR_SIZE(l1));
    initSingleListInt(list2, l2, ARR_SIZE(l2));
    struct ListNode* ret = (struct ListNode*)malloc(sizeof(struct ListNode));
    ret = mergeTwoLists(list1, list2);
    printSingleListInt(ret);
}