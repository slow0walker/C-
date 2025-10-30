#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() 
{
    int a, b, c, d, largest, smallest;
    printf("Enter four integers: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    largest = a;
    if (b > largest) largest = b;
    if (c > largest) largest = c;
    if (d > largest) largest = d;

    smallest = a;
    if (b < smallest) smallest = b;
    if (c < smallest) smallest = c;
    if (d < smallest) smallest = d;

    printf("Largest: %d\nSmallest: %d\n", largest, smallest);
    return 0;
}