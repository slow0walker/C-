#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand((unsigned)time(NULL));

    for (int i = 0; i < 1000; i++) {
        int r = rand();
        printf("%d", r & 1);    // 只输出最低位
    }

    printf("\n");
    return 0;
}
