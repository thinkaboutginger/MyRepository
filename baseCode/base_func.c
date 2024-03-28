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