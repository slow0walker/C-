#define _CRT_SECURE_NO_WARNINGS 1
#include <time.h>
#include <stdio.h>
#include <stdlib.h>


double rand_double(void)
{
    return (double)rand() / (RAND_MAX + 1.0);
}

int main()
{
    srand((unsigned)time(NULL));
    int n = 1;
    while (n<10)
    {
        printf("rand_double=%f\n", rand_double());
        n++;

    }
    return 0;
}
