#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_REMIND 50
#define MSG_LEN 60
#define MONTH_DAYS 31  // 每月最大天数（简化处理，实际可根据月份调整）

int read_line(char str[], int n);
int compare_dates(const char* date1, const char* date2);
void sort_reminders(char reminders[][MSG_LEN + 6], int num_remind);

int main()
{
    char reminders[MAX_REMIND][MSG_LEN + 6];  // 格式："mm/dd 时间 提醒"
    char date_str[6], time_str[6], msg_str[MSG_LEN + 1];
    int month, day, num_remind = 0;

    for (;;)
    {
        if (num_remind == MAX_REMIND)
        {
            printf("-- NO Space left --\n");
            break;
        }

        printf("Enter date(mm/dd), time(hh:mm) and reminder: ");
        if (scanf("%5[^ ] %5[^ ]", date_str, time_str) != 2) break;

        // 解析日期并检查有效性（功能(a)）
        if (sscanf(date_str, "%d/%d", &month, &day) != 2 ||
            month < 1 || month > 12 || day < 1 || day > MONTH_DAYS)
        {
            printf("Invalid date! Skipping reminder.\n");
            read_line(msg_str, 0);  // 清空输入缓冲区
            continue;
        }

        read_line(msg_str, MSG_LEN);

        // 拼接提醒信息：日期 + 时间 + 提醒内容
        char full_msg[MSG_LEN + 6] = { 0 };
        strcat(full_msg, date_str);
        strcat(full_msg, " ");
        strcat(full_msg, time_str);
        strcat(full_msg, " ");
        strcat(full_msg, msg_str);

        // 插入排序（按日期、时间排序，功能(b)）
        int i, j;
        for (i = 0; i < num_remind; i++)
        {
            if (compare_dates(full_msg, reminders[i]) < 0)
                break;
        }
        for (j = num_remind; j > i; j--)
        {
            strcpy(reminders[j], reminders[j - 1]);
        }
        strcpy(reminders[i], full_msg);

        num_remind++;
    }

    // 排序（确保最终按日期、时间有序，功能(b)）
    sort_reminders(reminders, num_remind);

    printf("\nYearly Reminder List\n");
    printf("Date    Time    Reminder\n");
    for (int i = 0; i < num_remind; i++)
    {
        printf("%s\n", reminders[i]);
    }
    return 0;
}

// 比较两个日期时间字符串的先后（格式："mm/dd hh:mm"）
int compare_dates(const char* date1, const char* date2)
{
    int m1, d1, h1, min1, m2, d2, h2, min2;
    sscanf(date1, "%d/%d %d:%d", &m1, &d1, &h1, &min1);
    sscanf(date2, "%d/%d %d:%d", &m2, &d2, &h2, &min2);

    if (m1 != m2) return m1 - m2;
    if (d1 != d2) return d1 - d2;
    if (h1 != h2) return h1 - h2;
    return min1 - min2;
}

// 排序提醒数组（冒泡排序，按日期时间升序）
void sort_reminders(char reminders[][MSG_LEN + 6], int num_remind)
{
    for (int i = 0; i < num_remind - 1; i++)
    {
        for (int j = 0; j < num_remind - 1 - i; j++)
        {
            if (compare_dates(reminders[j], reminders[j + 1]) > 0)
            {
                char temp[MSG_LEN + 6];
                strcpy(temp, reminders[j]);
                strcpy(reminders[j], reminders[j + 1]);
                strcpy(reminders[j + 1], temp);
            }
        }
    }
}

int read_line(char str[], int n)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
    {
        if (i < n - 1) str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}