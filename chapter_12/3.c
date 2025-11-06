#include <stdio.h>
#define MAX_LEN 100


int main()
{
	char msg[MAX_LEN];
	char ch;
	int i = 0;
	while ((ch = getchar()) != '\n' && (msg + i) < msg+MAX_LEN - 1)
	{
		*(msg + i) = ch;
		i++;
	}
	msg[i] = '\0';


	while ((msg + i - 1) >= msg)
	{
		putchar(*(msg + i - 1));
		i--;
	}
	return 0;
}
