#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;

void make_empty(void)
{
	top = 0;
}

bool is_empty(void) {
    return top == 0;
}

bool is_full(void) {
    return top == STACK_SIZE;
}

void stack_overflow(void) {
    printf("Stack overflow\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void) {
    printf("Stack underflow\n");
    exit(EXIT_FAILURE);
}

void push(char c) {
    if (is_full()) {
        stack_overflow();
    }
    else {
        contents[top++] = c;
    }
}

char pop(void) {
    if (is_empty()) {
        stack_underflow();
    }
    else {
        return contents[--top];
    }
}

int main()
{
    char ch;
    bool matched = true;

    printf("Enter parentheses and/or braces: ");
    while ((ch=getchar())!='\n')
    {
        if (ch == '(' || ch == '{')
        {
            push(ch);
        }
        else if(ch==')'||ch=='}')
        {
            //提前判断 is_empty()，是为了优雅地处理错误，而不是被动崩溃式终止程序。
            if (is_empty())
            {
                matched = false;
                break;
            }
            char top_char = pop();
            if ((ch == ')' && top_char != '(') || (ch == '}' && top_char != '{'))
            {
                matched = false;//说明没匹配
                break;
            }
        }
    }
    if (matched && is_empty()) {
        printf("Parentheses/braces are nested properly\n");
    }
    else {
        printf("Parentheses/braces are not nested properly\n");
    }

    return 0;
}