#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// 定义存储区号和国家（地区）的结构体
typedef struct {
    int code;
    char* country;
} CountryCode;

int main() {
    // 定义国际电话区号与国家（地区）的对应数组
    CountryCode country_codes[] = {
        {86, "中国"},
        {1, "美国/加拿大"},
        {44, "英国"},
        {81, "日本"},
        {33, "法国"},
        // 可根据需要补充更多区号
    };
    int n = sizeof(country_codes) / sizeof(country_codes[0]);

    int area_code;
    printf("请输入国际电话区号：");
    scanf("%d", &area_code);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (country_codes[i].code == area_code) {
            printf("对应的国家（地区）是：%s\n", country_codes[i].country);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("未找到对应的国家（地区），请检查区号是否正确。\n");
    }

    return 0;
}