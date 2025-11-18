#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* month_names[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

int main(int argc, char* argv[]) {
    int month, day, year;
    if (argc != 2) {
        fprintf(stderr, "usage: %s date\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (sscanf(argv[1], "%d-%d-%d", &month, &day, &year) != 3 &&
        sscanf(argv[1], "%d/%d/%d", &month, &day, &year) != 3) {
        fprintf(stderr, "Invalid date format. Use mm-dd-yyyy or mm/dd/yyyy\n");
        exit(EXIT_FAILURE);
    }
    if (month < 1 || month > 12 || day < 1 || day > 31) {
        fprintf(stderr, "Invalid date values\n");
        exit(EXIT_FAILURE);
    }
    printf("%s %d, %d\n", month_names[month - 1], day, year);
    return 0;
}