#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// ��ʱ��ת��Ϊ����ҹ��ʼ�ķ�����
int toMinutes(int hour, int minute) {
    return hour * 60 + minute;
}

int main() {
    int inputHour, inputMinute, inputTotal, minDiff, currentDiff;
    int departHours[] = { 8, 9, 11, 12, 14, 16, 15, 19, 21 };
    int departMins[] = { 0, 43, 19, 47, 0, 0, 45, 0, 45 };
    int arriveHours[] = { 10, 11, 1, 3, 4, 5, 9, 11, 11 };
    int arriveMins[] = { 16, 52, 31, 0, 8, 55, 20, 58, 58 };
    int index = 0, i;

    printf("Enter a 24-hour time (hh:mm): ");
    scanf("%d:%d", &inputHour, &inputMinute);
    inputTotal = toMinutes(inputHour, inputMinute);

    minDiff = 1440; // һ��ķ���������ʼ��Ϊ���ֵ
    for (i = 0; i < 9; i++) {
        int departTotal = toMinutes(departHours[i], departMins[i]);
        currentDiff = abs(inputTotal - departTotal);
        if (currentDiff < minDiff) {
            minDiff = currentDiff;
            index = i;
        }
    }

    printf("Closest departure time is %d:%.2d %s, arriving at %d:%.2d %s\n",
        departHours[index] % 12 == 0 ? 12 : departHours[index] % 12,
        departMins[index],
        departHours[index] < 12 ? "a.m." : "p.m.",
        arriveHours[index] % 12 == 0 ? 12 : arriveHours[index] % 12,
        arriveMins[index],
        arriveHours[index] < 12 ? "a.m." : "p.m.");

    return 0;
}