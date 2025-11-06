#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void max_min(int* arr, int n, int* max, int* min) {
    *max = *min = *arr;
    int* p = arr + 1; // 指针从第二个元素开始遍历

    for (; p < arr + n; p++) {
        if (*p > *max) *max = *p;
        if (*p < *min) *min = *p;
    }
}

int main() {
    int arr[] = { 3, 1, 4, 1, 5, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int max, min;

    max_min(arr, n, &max, &min);
    printf("Max: %d, Min: %d\n", max, min);

    return 0;
}