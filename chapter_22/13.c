#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int hour;
    int minute;
} Time;

Time read_time(FILE* fp) {
    Time t;
    fscanf(fp, "%d:%d", &t.hour, &t.minute);
    return t;
}

int time_diff(Time t1, Time t2) {
    return (t2.hour - t1.hour) * 60 + (t2.minute - t1.minute);
}

void print_time(Time t) {
    printf("%02d:%02d", t.hour, t.minute);
}

int main(void) {
    FILE* fp = fopen("flights.dat", "r");
    if (fp == NULL) {
        fprintf(stderr, "Can't open flights.dat\n");
        exit(EXIT_FAILURE);
    }
    Time depart, arrive;
    while (fscanf(fp, "%d:%d", &depart.hour, &depart.minute) == 2 &&
        fscanf(fp, "%d:%d", &arrive.hour, &arrive.minute) == 2) {
        print_time(depart);
        printf(" - ");
        print_time(arrive);
        int diff = time_diff(depart, arrive);
        printf(" (%d hours %d minutes)\n", diff / 60, diff % 60);
    }
    fclose(fp);
    return 0;
}