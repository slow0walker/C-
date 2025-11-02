#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)
{
    int i, n;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("%10d%10d\n", i, i * i);
        
        if (i % 24 == 0) {
            printf("Press Enter to continue...");
            getchar(); //消耗换行符
            getchar();//读取回车键
        }
    }

    return 0;
}