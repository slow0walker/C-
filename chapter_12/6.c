#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// split函数：返回 pivot 位置的指针
int* split(int* low, int* high) {
    int pivot = *low;
    while (low < high) {
        while (low < high && *high >= pivot) high--;
        *low = *high;
        while (low < high && *low <= pivot) low++;
        *high = *low;
    }
    *low = pivot;
    return low;
}

void quicksort(int* low, int* high) {
    if (low < high) {
        int* middle = split(low, high);
        quicksort(low, middle - 1);
        quicksort(middle + 1, high);
    }
}

int main() {
    int arr[] = { 5, 2, 9, 1, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, arr + n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}