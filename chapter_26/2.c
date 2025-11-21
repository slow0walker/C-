#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void msg1(void) {
    printf("That's all, ");
}

void msg2(void) {
    printf("folks!\n");
}

int main(void)
{
    atexit(msg2);
    atexit(msg1);  // 后注册的先执行
    return 0;
}
