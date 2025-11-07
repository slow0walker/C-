#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>

#define MAX_WORDS 30
#define MAX_WORD_LEN 20

void read_words(char words[MAX_WORDS][MAX_WORD_LEN]) {
    char ch;
    int word_idx = 0;
    int char_idx = 0;

    while ((ch = getchar()) != '\n') {
        if (isalpha((unsigned char)ch)) {
            words[word_idx][char_idx++] = ch;
        }
        else if (char_idx > 0) {
            words[word_idx][char_idx] = '\0';
            word_idx++;
            char_idx = 0;
        }
    }
    if (char_idx > 0) {
        words[word_idx][char_idx] = '\0';
    }
}

int main() {
    char words[MAX_WORDS][MAX_WORD_LEN];
    printf("Enter a sentence: ");
    read_words(words);

    printf("Words:\n");
    for (int i = 0; words[i][0] != '\0'; i++) {
        printf("%s\n", words[i]);
    }
    return 0;
}