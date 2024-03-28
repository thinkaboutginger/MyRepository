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

void SWAP_INT(int *a, int *b);
void SWAP_CHAR(char *a, char *b);

#endif /* BASE_DEF_H */