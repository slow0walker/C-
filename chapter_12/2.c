#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#define MAX_LEN 100

bool is_palindrome(char* start, char* end)
{
	while (start < end)
	{
		if (*start == *end)
		{
			return true;
		}
		start++;
		end--;
	}
	return false;
}

int main()
{
	char msg[MAX_LEN];
	char ch;
	char* p = msg;

	printf("Enter a message: ");
	while ((ch = getchar()) != '\n' && p < msg + MAX_LEN - 1) {
		*p++ = ch;
	}
	*p = '\0';
	p--; // 指针指向最后一个有效字符
	if (is_palindrome(msg, p)) {
		printf("The message is a palindrome.\n");
	}
	else {
		printf("The message is not a palindrome.\n");
	}

	return 0;
}