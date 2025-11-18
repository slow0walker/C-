#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    FILE* fp;
    int item;
    double price;
    int month, day, year;
    if (argc != 2) {
        fprintf(stderr, "usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    printf("%-10s %-10s %-15s\n", "Item", "Unit Price", "Purchase Date");
    while (fscanf(fp, "%d,%lf,%d/%d/%d", &item, &price, &month, &day, &year) == 5) {
        printf("%-10d $%-9.2f %d/%d/%d\n", item, price, month, day, year);
    }
    fclose(fp);
    return 0;
}