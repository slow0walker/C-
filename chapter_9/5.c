#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
# define MAX 99

void create_magic_square(int n, int magic[][MAX])
{
    // 初始化为 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            magic[i][j] = 0;

    // 起始位置：第一行中间
    int num = 1;
    int row = 0;
    int col = n / 2;

    while (num <= n * n)
    {
        magic[row][col] = num;

        // 保存当前位置
        int prev_row = row;
        int prev_col = col;

        // 移动到右上角
        row -= 1;
        col += 1;

        // 边界调整
        if (row < 0)
            row = n - 1;  // 超出上边，回到底部
        if (col == n)
            col = 0;      // 超出右边，回到最左列

        // 如果新位置已被占用
        if (magic[row][col] != 0)
        {
            row = prev_row + 1;  // 放在原位置的正下方
            col = prev_col;
            if (row == n)
                row = 0;
        }

        num++;
    }
}

void print_magic_square(int n, int magic[][MAX])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%4d", magic[i][j]);
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter an odd number (n): ");
    scanf("%d", &n);

    if (n % 2 == 0 || n < 1)
    {
        printf("n must be an odd positive integer.\n");
        return 1;
    }

    int magic[MAX][MAX];
    //生成幻方
    create_magic_square(n,magic);
    // 输出幻方
    printf("\nMagic Square of size %d:\n", n);
    print_magic_square(n, magic);
    return 0;
}