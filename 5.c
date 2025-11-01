#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
    int main() 
    {
        int num, digit;
        printf("Enter an interger:£º");
        scanf("%d", &num);
        do {
            digit = num % 10;  
            printf("%d", digit);
            num = num / 10;    
        } while (num != 0);
        printf("\n");
        return 0;
    }
