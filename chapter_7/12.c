#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	double value = 0.0, num;
    char op;

    printf("Enter an expression: ");
    scanf("%lf", &value);
    while (scanf(" %c%lf", &op, &num) == 2) {
        switch (op) {
        case '+':
            value += num;
            break;
        case '-':
            value -= num;
            break;
        case '*':
            value *= num;
            break;
        case '/':
            if (num == 0) {
                printf("Error: Division by zero\n");
                return 1;
            }
            value /= num;
            break;
        default:
            printf("Invalid operator\n");
            return 1;
        }
    }

    printf("Value of expression: %.2f\n", value);
    return 0;
}