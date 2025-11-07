#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

void count_chars(const char* str, int count[]) {
    while (*str != '\0') {
        if (isalpha((unsigned char)*str)) {
            count[toupper((unsigned char)*str) - 'A']++;
        }
        str++;
    }
}

bool are_anagrams(const char* word1, const char* word2) {
    int count1[26] = { 0 }, count2[26] = { 0 };
    count_chars(word1, count1);
    count_chars(word2, count2);
    for (int i = 0; i < 26; i++) {
        if (count1[i] != count2[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    char w1[] = "listen", w2[] = "silent";
    printf("%s\n", are_anagrams(w1, w2) ? "Anagrams" : "Not anagrams");
    return 0;
}