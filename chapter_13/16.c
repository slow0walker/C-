#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

void reverse(char* message) {
    char* left = message;
    char* right = message + strlen(message) - 1;
    while (left < right) {
        char temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}

int main() {
    char msg[] = "Hello";
    reverse(msg);
    printf("%s\n", msg); // Êä³ö"olleH"
    return 0;
}
