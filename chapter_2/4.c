#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	float amount,amount_add;
	printf("Enter an amount :");
	scanf("%f", &amount);
	amount_add = amount * (1 + 0.05);
	printf("with tax added: $%.2f", amount_add);

	return 0;
}