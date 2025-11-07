#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>

void encrypt(char* message, int shift) {
    while (*message != '\0') {
        if (isalpha((unsigned char)*message)) {
            char base = isupper((unsigned char)*message) ? 'A' : 'a';
            *message = (char)((*message - base + shift) % 26 + base);
        }
        message++;
    }
}

int main() {
    char msg[] = "Hello World";
    encrypt(msg, 3);
    printf("Encrypted: %s\n", msg); // Êä³ö"Khoor Zruog"
    return 0;
}
