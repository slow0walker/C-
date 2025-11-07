#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_PLANETS 9

// 自定义不区分大小写的字符串比较函数
int strcmp_case_insensitive(const char* s1, const char* s2) {
    while (*s1 && *s2) {
        char c1 = toupper((unsigned char)*s1);
        char c2 = toupper((unsigned char)*s2);
        if (c1 != c2) {
            return c1 - c2;
        }
        s1++;
        s2++;
    }
    return toupper((unsigned char)*s1) - toupper((unsigned char)*s2);
}

int main(int argc, char* argv[]) {
    const char* planets[] = { "Mercury", "Venus", "Earth",
                       "Mars", "Jupiter", "Saturn",
                       "Uranus", "Neptune", "Pluto" };
    int i, j;

    for (i = 1; i < argc; i++) {
        for (j = 0; j < NUM_PLANETS; j++) {
            if (strcmp_case_insensitive(argv[i], planets[j]) == 0) {
                printf("%s is planet %d\n", argv[i], j + 1);
                break;
            }
        }
        if (j == NUM_PLANETS) {
            printf("%s is not a planet\n", argv[i]);
        }
    }

    return 0;
}