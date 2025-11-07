#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int evaluate_RPN_expression(const char* expression) {
    char* token = strtok((char*)expression, " ");
    while (token != NULL) {
        if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') {
            int b = pop();
            int a = pop();
            switch (token[0]) {
            case '+': push(a + b); break;
            case '-': push(a - b); break;
            case '*': push(a * b); break;
            case '/': push(a / b); break;
            }
        }
        else {
            push(atoi(token));
        }
        token = strtok(NULL, " ");
    }
    return pop();
}

int main() {
    char expr[] = "3 4 + 5 *";
    printf("Result: %d\n", evaluate_RPN_expression(expr)); // Êä³ö35
    return 0;
}