#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define MAX_INTS 10000

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int nums[MAX_INTS], count = 0, num;
    while (fscanf(fp, "%d", &num) == 1 && count < MAX_INTS) {
        nums[count++] = num;
    }
    fclose(fp);

    if (count == 0) {
        printf("No integers found.\n");
        return 0;
    }

    qsort(nums, count, sizeof(int), compare);

    int max = nums[count - 1];
    int min = nums[0];
    int median;
    if (count % 2 == 1) {
        median = nums[count / 2];
    }
    else {
        median = (nums[count / 2 - 1] + nums[count / 2]) / 2;
    }

    printf("Max: %d\nMin: %d\nMedian: %d\n", max, min, median);
    return 0;
}