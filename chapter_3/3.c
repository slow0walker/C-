#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

    int main() {
        char gs1_prefix[10], group_identifier[10], publisher_code[10], item_number[10], check_digit[5];

        // 提示用户输入ISBN，并按“-”分割各组
        printf("Enter ISBN: ");
        scanf("%[^-]-%[^-]-%[^-]-%[^-]-%s", gs1_prefix, group_identifier, publisher_code, item_number, check_digit);

        // 输出拆分后的信息
        printf("\nGS1 prefix: %s\n", gs1_prefix);
        printf("Group identifier: %s\n", group_identifier);
        printf("Publisher code: %s\n", publisher_code);
        printf("Item number: %s\n", item_number);
        printf("Check digit: %s\n", check_digit);

        return 0;
    }

