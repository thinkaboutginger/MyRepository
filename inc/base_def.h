#define BSEE_DEF_H
#ifdef BSEE_DEF_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef char INT8S;
typedef unsigned char INT8U;
typedef short INT16S;
typedef unsigned short INT16U;
typedef int INT32S;
typedef unsigned int INT32U;
typedef unsigned char BOOLEAN;
typedef double FP64;
typedef float FP32;

#define TRUE 1
#define FALSE 0
#define ARR_SIZE(a) (sizeof(a) / sizeof(a[0]))

#endif /* BSEE_DEF_H */