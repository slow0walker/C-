#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define MAX_SIZE 100
void selection_sort(int a[], int n);

int main() {
    int arr[MAX_SIZE];
    int n;
    printf("Enter the number of integers: ");
    scanf("%d", &n);
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    selection_sort(arr, n);
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;

}

void selection_sort(int a[], int n)
{
    if (n <= 1)return;

    //找出最大元素所在的下标
    int max_idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[max_idx])max_idx = i;
    }

    // 交换最大元素和最后一个元素
    int temp = a[max_idx];
    a[max_idx] = a[n - 1];
    a[n - 1] = temp;

    //递归排序前n - 1个元素
    selection_sort(a, n - 1);
}