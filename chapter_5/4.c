#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() 
{
    float speed;
    printf("Enter wind speed (miles per hour): ");
    scanf("%f", &speed);

    if (speed < 1)
        printf("Calm���޷磩\n");
    else if (speed < 4)
        printf("Light air����磩\n");
    else if (speed < 28)
        printf("Breeze��΢�磩\n");
    else if (speed < 48)
        printf("Gale����磩\n");
    else if (speed < 64)
        printf("Storm�����磩\n");
    else
        printf("Hurricane��쫷磩\n");

    return 0;
}