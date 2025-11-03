#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

int main() {
	bool digit_seen[10] = { false };
	int digit;
	long long n;
	int digit_repeated[10] = { 0 };

	printf("Enter a number:");
	scanf_s("%lld", &n);

	for (;;)
	{
		if (n <= 0)break;
		while (n > 0)
		{
			digit = n % 10;
			if (digit_seen[digit])
			{
				digit_repeated[digit] = digit;
			}
			digit_seen[digit] = true;
			n /= 10;
		}
		printf("Repeated digit(s): ");
		for (int i = 9; i >= 0; --i)
		{
			if (digit_repeated[i] == 0)
				continue;
			printf("%d ", digit_repeated[i]);
		}
		for (int i = 0; i < 10; ++i)
		{
			digit_repeated[i] = 0;
		}
		printf("\nEnter a number:");
		scanf_s("%lld", &n);

	}

	printf("\n");

	return 0;
}