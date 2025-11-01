#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int fact(int n) {
	int result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}
int main()
{
	int n;
	printf("Enter a number n: ");
	scanf("%d", &n);

	int i = 1;
	double sum = 1.0;  // e 的近似值从 1 开始

	while (i <= n)
	{
		int n_fact = fact(i);
		sum += 1.0 / n_fact;
		i++;
	}
	printf("e ≈ %.15lf\n", sum);
	return 0;
}