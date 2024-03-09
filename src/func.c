#include "base_def.h"

unsigned int array[7] = {2, 3, 5, 7, 11, 13, 17};
unsigned int output[2] = {0};
void func(unsigned int input)
{
    unsigned int ret[2] = {0};
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 7; j++) {
            if (array[i] + array[j] == input) {
                output[0] = i;
                output[1] = j;
                return; /* 找到第一组解就返回 */
            }
        }
    }
}

void FindTarget(void)
{
    func(17);
    printf("%d, %d\r\n", output[0], output[1]);
    return;
}