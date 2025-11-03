#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

int main()
{
	bool digit_seen[10] = { false };
	int digit;
	long long n;
	int digit_repeated[10] = { 0 };

	printf("Enter a number:");
	scanf_s("%lld", &n);

	/*while (n > 0)
	{
		digit = n % 10;
		if (digit_seen[digit])
		{
			digit_repeated[digit]+=1;
		}
		else
		{
			digit_repeated[digit] = 1;
		}
		digit_seen[digit] = true;
		n /= 10;
	}*/
	while (n > 0)
	{
		digit = n % 10;
		digit_repeated[digit]++;
		n /= 10;
	}
	printf("Digit:      ");
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", i);
	}

	printf("\nOccurrnces: ");
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", digit_repeated[i]);
	}

	return 0;
}