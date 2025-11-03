#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>
#define NUM 100

int main()
{
	char message[NUM] = "";
	printf("Enter message:");
	fgets(message, NUM, stdin); // ¶ÁÈ¡×Ö·û´®
	//printf("%s", message);

	int i = 0;
	printf("In B1FF-speak:");
	while (message[i] != '\0')
	{
		if (isalpha(message[i]))
		{
			char ch = toupper(message[i]);
			switch (ch)
			{
			case 'A':putchar('4'); break;
			case 'B':putchar('8'); break;
			case 'E':putchar('3'); break;
			case 'I':putchar('1'); break;
			case 'O':putchar('0'); break;
			case 'S':putchar('5'); break;

			default:putchar(ch);
				break;
			}
		}
		else
		{
			printf("%c", message[i]);
		}
		i++;
	}
	printf("!!!!!!!!!!");


	return 0;
}