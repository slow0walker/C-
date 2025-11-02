#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>
int gcd(int a, int b)
{
	while (b != 0)
	{
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main()
{
	int num1, den1, num2, den2, result_num, result_den;
	char op;

	printf("Enter two fractions separated by an operator(+,-,*,/):");
	scanf_s("%d/%d%c%d/%d", &num1, &den1, &op, &num2, &den2);

	switch (op)
	{
	case '+':
		result_num = num1 * den2 + num2 * den1;
		result_den = den1 * den2;
		break;
	case '-':
		result_num = num1 * den2 - num2 * den1;
		result_den = den1 * den2;
		break;
	case '*':
		result_num = num1 * num2;
		result_den = den1 * den2;
		break;
	case '/':
		result_num = num1 * den2;
		result_den = den1 * num2;
		break;
	default:
		printf("Invalid operator\n");
		return 1;
		break;
	}

	int gcd_val = gcd(abs(result_num), abs(result_den));
	result_num /= gcd_val;
	result_den /= gcd_val;

	
	printf("The result is %d/%d\n", result_num, result_den);

	return 0;
}