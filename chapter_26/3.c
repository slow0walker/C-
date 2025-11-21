#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cmp_int(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

void test(int n)
{
    int* a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        a[i] = n - i;   // ÄæÐò

    clock_t start = clock();
    qsort(a, n, sizeof(int), cmp_int);
    clock_t end = clock();

    printf("%d numbers: %.6f seconds\n", n,
        (double)(end - start) / CLOCKS_PER_SEC);

    free(a);
}

int main(void)
{
    test(1000);
    test(10000);
    test(100000);
    return 0;
}
