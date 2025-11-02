#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    short fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    printf("Factorial of %d: %hd\n", n, fact);
    // short最大值为32767，n最大为7（7! = 5040，8! = 40320 > 32767）
    return 0;
}
#include <stdio.h>

int main() {
    int n, fact = 1;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    printf("Factorial of %d: %d\n", n, fact);
    // int最大值为2147483647，n最大为12（12! = 479001600，13! = 6227020800 > 2147483647）
    return 0;
}

#include <stdio.h>

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    printf("Factorial of %d: %ld\n", n, fact);
    // long最大值为9223372036854775807，n最大为20（20! = 2432902008176640000，21! = 51090942171709440000 > 9223372036854775807）
    return 0;
}

#include <stdio.h>

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    printf("Factorial of %d: %lld\n", n, fact);
    // long long最大值为9223372036854775807，n最大为20（同long，因21!超出范围）
    return 0;
}