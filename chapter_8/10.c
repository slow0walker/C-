#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
    // 存储起飞时间（从午夜开始的分钟数）
    int departures[] = {
        8 * 60,      // 8:00 a.m.
        9 * 60 + 43,   // 9:43 a.m.
        11 * 60 + 19,  // 11:19 a.m.
        12 * 60 + 47,  // 12:47 p.m.
        14 * 60,     // 2:00 p.m.
        15 * 60 + 45,  // 3:45 p.m.
        19 * 60,     // 7:00 p.m.
        21 * 60 + 45   // 9:45 p.m.
    };
    // 存储抵达时间（从午夜开始的分钟数）
    int arrivals[] = {
        10 * 60 + 16,  // 10:16 a.m.
        11 * 60 + 52,  // 11:52 a.m.
        13 * 60 + 31,  // 1:31 p.m.
        15 * 60,     // 3:00 p.m.
        16 * 60 + 8,   // 4:08 p.m.
        17 * 60 + 55,  // 5:55 p.m.
        21 * 60 + 20,  // 9:20 p.m.
        23 * 60 + 58   // 11:58 p.m.
    };
    int num_flights = sizeof(departures) / sizeof(departures[0]);
    //到达时间，与午夜差的总时间
    int input_hour, input_min, input_total;
    int min_diff = 1440, closest_idx = 0;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &input_hour, &input_min);
    input_total = input_hour * 60 + input_min;

    for (int i = 0; i < num_flights; i++) {
        int diff = abs(input_total - departures[i]);
        if (diff < min_diff) {
            min_diff = diff;
            closest_idx = i;
        }
    }

    // 格式化输出起飞和抵达时间
    int dep_h = departures[closest_idx] / 60;
    int dep_m = departures[closest_idx] % 60;
    int arr_h = arrivals[closest_idx] / 60;
    int arr_m = arrivals[closest_idx] % 60;

    printf("Closest departure time is ");
    if (dep_h < 12) {
        printf("%d:%02d a.m., ", dep_h, dep_m);
    }
    else if (dep_h == 12) {
        printf("12:%02d p.m., ", dep_m);
    }
    else {
        printf("%d:%02d p.m., ", dep_h - 12, dep_m);
    }

    printf("arriving at ");
    if (arr_h < 12) {
        printf("%d:%02d a.m.\n", arr_h, arr_m);
    }
    else if (arr_h == 12) {
        printf("12:%02d p.m.\n", arr_m);
    }
    else {
        printf("%d:%02d p.m.\n", arr_h - 12, arr_m);
    }

    return 0;
}