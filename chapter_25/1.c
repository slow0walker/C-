#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(void) {
    // 获取当前的本地设置
    char* current_locale = setlocale(LC_ALL, NULL);

    printf("当前 locale: %s\n", current_locale);

    // 检查是否和 "C" locale 一致
    if (strcmp(current_locale, "C") == 0) {
        printf("当前 locale 与 \"C\" 地区一致。\n");
    }
    else {
        printf("当前 locale 与 \"C\" 地区不一致。\n");
    }

    return 0;
}
