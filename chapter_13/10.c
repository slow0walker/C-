#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverse_name(char* name) {
    // 定位姓的起始（从后往前找第一个非空格的字符，再往前找空格）
    char* last = name + strlen(name) - 1;
    while (last >= name && isspace((unsigned char)*last)) last--;
    char* surname_start = last;
    while (surname_start >= name && !isspace((unsigned char)*surname_start)) surname_start--;
    surname_start++;

    // 定位名的首字母
    char* first = name;
    while (*first != '\0' && isspace((unsigned char)*first)) first++;
    char first_init = toupper((unsigned char)*first);

    // 构造结果
    char result[100] = { 0 };
    strncpy(result, surname_start, last - surname_start + 1);
    strcat(result, ", ");
    result[strlen(result)] = first_init;
    strcat(result, ".");

    // 复制回原字符串
    strcpy(name, result);
}

int main() {
    char name[100];
    printf("Enter a first and last name: ");
    // 读取整行输入（包含空格）
    int i = 0;
    char ch;
    while ((ch = getchar()) != '\n' && i < 99) {
        name[i++] = ch;
    }
    name[i] = '\0';

    reverse_name(name);
    printf("%s\n", name);

    return 0;
}