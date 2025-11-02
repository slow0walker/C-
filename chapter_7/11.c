#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>

int main() {
    char first[50], last[50], ch;
    int firstFlag = 0, lastFlag = 0;

    printf("Enter a first and last name: ");
    // 读取名的首字母前的空格
    while ((ch = getchar()) == ' ');
    ungetc(ch, stdin);
    // 读取名的首字母
    scanf("%c", &first[0]);
    first[1] = '\0';
    // 读取名的剩余部分（忽略中间空格）
    while ((ch = getchar()) != ' ' && ch != '\n') {}
    // 读取姓前的空格
    while ((ch = getchar()) == ' ');
    ungetc(ch, stdin);
    // 读取姓
    scanf("%s", last);

    printf("%s, %c.\n", last, toupper(first[0]));
    return 0;
}