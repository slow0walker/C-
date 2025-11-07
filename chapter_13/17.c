#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool is_palindrome(const char* message) {
    const char* left = message;
    const char* right = message + strlen(message) - 1;
    while (left < right) {
        while (left < right && !isalnum((unsigned char)*left)) left++;
        while (left < right && !isalnum((unsigned char)*right)) right--;
        if (tolower((unsigned char)*left) != tolower((unsigned char)*right)) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    char msg[] = "Race car";
    printf("%s\n", is_palindrome(msg) ? "Palindrome" : "Not palindrome");
    return 0;
}
