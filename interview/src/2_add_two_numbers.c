#include "base_def.h"
#include "include.h"

void insert(struct ListNode* head, int value)
{
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

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = 0;
    head->next = NULL;
    int jinwei = 0;
    while (l1 && l2) {
        int tmp = l1->val + l2->val + jinwei;
        int num = tmp % 10;
        jinwei = tmp / 10;
        insert(head, num);
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1) {
        int tmp = l1->val + jinwei;
        int num = tmp % 10;
        jinwei = tmp / 10;
        insert(head, num);
        l1 = l1->next;
    }
    while(l2) {
        int tmp = l2->val + jinwei;
        int num = tmp % 10;
        jinwei = tmp / 10;
        insert(head, num);
        l2 = l2->next;
    }
    if (jinwei) {
        insert(head, jinwei);
    }
    return head->next;
}

void func2(void)
{
    int nums1[] = {9,9,9,9,9,9,9};
    int len1 = ARR_SIZE(nums1);
    struct ListNode *l1 = (struct ListNode *)malloc(len1 * sizeof(struct ListNode));
    initSingleListInt(l1, nums1, len1);
    int nums2[] = {9,9,9,9};
    int len2 = ARR_SIZE(nums2);
    struct ListNode *l2 = (struct ListNode *)malloc(len2 * sizeof(struct ListNode));
    initSingleListInt(l2, nums2, len2);
    struct ListNode *ret = addTwoNumbers(l1, l2);
    printSingleListInt(ret);
}