#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int main() {
    const char* months[] = { "January", "February", "March", "April", "May", "June",
                           "July", "August", "September", "October", "November", "December" };
    int mm, dd, yyyy;
    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &mm, &dd, &yyyy);

    printf("You entered the date %s %d, %d\n", months[mm - 1], dd, yyyy);
    return 0;
}