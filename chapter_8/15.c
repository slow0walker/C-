#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 80

int main(void)
{
    char message[MAX_LEN];
    char ch;
    int i = 0;

    printf("Enter message to be encrypted: ");
    while ((ch = getchar()) != '\n' && i < MAX_LEN - 1)
    {
        message[i++] = ch;
    }
    message[i] = '\0';

    int n;
    printf("Enter shift amount (1-25): ");
    scanf_s("%d", &n);

    printf("Encrypted message: ");
    i = 0;  //  重新从头开始加密
    while (message[i] != '\0')
    {
        if (isalpha(message[i]))
        {
            ch = message[i];
            if (isupper(ch))
                putchar(((ch - 'A') + n) % 26 + 'A');
            else
                putchar(((ch - 'a') + n) % 26 + 'a');
        }
        else
        {
            putchar(message[i]);
        }
        i++;
    }

    printf("\n");
    return 0;
}
