#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    int hour, minute;
    char period[5]="", ch;
    printf("Enter a 12-hour time: ");
    scanf("%d:%d", &hour, &minute);
    // 读取标识
    while ((ch = getchar()) != '\n') {
        if (isalpha(ch)) {
            strncat(period, &ch, 1);
        }
    }
    period[0] = toupper(period[0]); 

    // 转换为24小时制
    if (period[0] == 'P' && hour != 12) {
        hour += 12;
    }
    else if (period[0] == 'A' && hour == 12) {
        hour = 0;
    }

    printf("Equivalent 24-hour time: %02d:%02d\n", hour, minute);
    return 0;
}