#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void) {
    int mm, dd, yy;
    int earliestMm = 0, earliestDd = 0, earliestYy = 0;
    int isFirst = 1;

    while (1) {
        printf("Enter a date (mm/dd/yy): ");
        scanf("%d/%d/%d", &mm, &dd, &yy);

        if (mm == 0 && dd == 0 && yy == 0) {
            break;
        }

        if (isFirst) {
            earliestMm = mm;
            earliestDd = dd;
            earliestYy = yy;
            isFirst = 0;
        }
        else {
            if (yy < earliestYy ||
                (yy == earliestYy && mm < earliestMm) ||
                (yy == earliestYy && mm == earliestMm && dd < earliestDd)) {
                earliestMm = mm;
                earliestDd = dd;
                earliestYy = yy;
            }
        }
    }

    printf("%d/%d/%d is the earliest date\n", earliestMm, earliestDd, earliestYy);
    return 0;
}