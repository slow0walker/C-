#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int num;
	int oct_digits[5] = { 0 };
	int index = 0;

	printf("Enter a number between 0 and 32767: ");
	scanf("%d", &num);

	while (num > 0 && index < 5)
	{
		oct_digits[index] = num % 8;
		num /= 8;
		++index;
	}
	printf("In octal, your number is: ");
	for (int i = 4; i >= 0; --i) 
	{  
		printf("%d", oct_digits[i]);
	}
	printf("\n");
	return 0;
}

//更简单的写法
/*
int main() 
{
    int num;
    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &num);
    // %05o 表示按八进制输出，不足5位则前面补0
    printf("In octal, your number is: %05o\n", num);
    return 0;
}
*/