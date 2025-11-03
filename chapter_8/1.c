#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

int main() {
	bool digit_seen[10] = { false };
	int digit;
	long long n;
	int digit_repeated[10] = { 0 };
	bool has_repeat = false;

	printf("Enter a number:");
	scanf_s("%lld", &n);

	while (n > 0)
	{
		digit = n % 10;
		if (digit_seen[digit])
		{
			digit_repeated[digit] = digit;
			has_repeat = true;
		}
		digit_seen[digit] = true;
		n /= 10;
	}
	if (has_repeat)
	{
		printf("Repeated digit(s): ");
		for (int i = 9; i >= 0; --i)
		{
			if (digit_repeated[i] == 0)
				continue;
			printf("%d ", digit_repeated[i]);
		}
	}
	else
	{
		printf("No repeated digit\n");

	}
	printf("\n");
 
	return 0;
}