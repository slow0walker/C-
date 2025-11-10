#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define MAX_FLIGHTS 10

// 定义时间结构，包含起飞和抵达时间（午夜开始的分钟数）
struct Time {
    int depart;
    int arrive;
};

// 存储航班时间的数组
struct Time flights[MAX_FLIGHTS] = {
    {480, 600},   // 8:00-10:00
    {720, 840},   // 12:00-14:00
    {960, 1080},  // 16:00-18:00
    // 可继续添加更多航班时间
};
int num_flights = 3;  // 实际航班数量

// 查找与输入时间最接近的起飞时间
void find_nearest_flight() {
    int input_time, min_diff = 1440, nearest_idx = -1;
    printf("请输入时间（午夜开始的分钟数）：");
    scanf("%d", &input_time);

    for (int i = 0; i < num_flights; i++) {
        int diff = abs(flights[i].depart - input_time);
        if (diff < min_diff) {
            min_diff = diff;
            nearest_idx = i;
        }
    }

    if (nearest_idx != -1) {
        printf("最接近的起飞时间：%d（%d:%02d），抵达时间：%d（%d:%02d）\n",
            flights[nearest_idx].depart,
            flights[nearest_idx].depart / 60, flights[nearest_idx].depart % 60,
            flights[nearest_idx].arrive,
            flights[nearest_idx].arrive / 60, flights[nearest_idx].arrive % 60);
    }
}

int main() {
    find_nearest_flight();
    return 0;
}