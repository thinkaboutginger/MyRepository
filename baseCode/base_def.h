#define BASE_DEF_H
#ifdef BASE_DEF_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

#define TRUE 1
#define FALSE 0

typedef char INT8S;
typedef unsigned char INT8U;
typedef short INT16S;
typedef unsigned short INT16U;
typedef int INT32S;
typedef unsigned int INT32U;
typedef unsigned char BOOLEAN;

#define ARR_SIZE(a) (sizeof(a) / sizeof(a[0]))

struct ListNode {
    int val;
    struct ListNode *next;
};

void SWAP_INT(INT32S *a, INT32S *b);
void SWAP_CHAR(INT8S *a, INT8S *b);
INT32S qsortInt(INT32S *num, INT32S numsSize);
INT32S qsortChar(INT8S *num, INT32S numsSize);
void initSingleListInt(struct ListNode *head, INT32S *data, INT32U dataLen);
void printSingleListInt(struct ListNode *list);

#endif /* BASE_DEF_H */