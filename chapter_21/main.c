#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h> // 用于offsetof

// 声明结构s
struct s {
    int a;
    char b;
    double c;
};

int main() {
    // 计算各成员的大小
    printf("size of a: %zu bytes\n", sizeof(((struct s*)0)->a));
    printf("size of b: %zu bytes\n", sizeof(((struct s*)0)->b));
    printf("size of c: %zu bytes\n", sizeof(((struct s*)0)->c));

    // 计算各成员的偏移量
    printf("offset of a: %zu bytes\n", offsetof(struct s, a));
    printf("offset of b: %zu bytes\n", offsetof(struct s, b));
    printf("offset of c: %zu bytes\n", offsetof(struct s, c));

    // 计算整个结构的大小
    printf("size of struct s: %zu bytes\n", sizeof(struct s));

    // 判断并分析空洞
    size_t expected_size = sizeof(int) + sizeof(char) + sizeof(double);
    if (sizeof(struct s) > expected_size) {
        printf("结构包含空洞：\n");
        // 分析b之后的空洞
        size_t hole1_start = offsetof(struct s, b) + sizeof(char);
        size_t hole1_size = offsetof(struct s, c) - hole1_start;
        printf("  空洞1：位置从%zu到%zu，大小%zu字节\n", hole1_start, offsetof(struct s, c) - 1, hole1_size);
        // 若结构末尾还有空洞（根据实际大小判断）
        size_t total_member_size = sizeof(int) + sizeof(char) + sizeof(double);
        if (sizeof(struct s) > total_member_size) {
            size_t hole2_start = total_member_size;
            size_t hole2_size = sizeof(struct s) - total_member_size;
            printf("  空洞2：位置从%zu到%zu，大小%zu字节\n", hole2_start, sizeof(struct s) - 1, hole2_size);
        }
    }
    else {
        printf("结构不包含空洞\n");
    }

    return 0;
}