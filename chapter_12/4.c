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
	int i = 0;
	while ((ch = getchar()) != '\n' && (msg + i) < msg + MAX_LEN - 1)
	{
		*(msg + i) = ch;
		i++;
	}
	msg[i] = '\0';
	char* q = msg + i - 1;
	if (is_palindrome(msg, q)) {
		printf("The message is a palindrome.\n");
	}
	else {
		printf("The message is not a palindrome.\n");
	}

	return 0;
}