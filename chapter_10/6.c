#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;

void make_empty(void)
{
	top = 0;
}

bool is_empty(void)
{
	return top == 0;
}

bool is_full(void)
{
	return top == STACK_SIZE;
}

void stack_overflow(void) {
    printf("Expression is too complex\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void) {
    printf("Not enough operands in expression\n");
    exit(EXIT_FAILURE);
}

void push(int i) {
    if (is_full()) {
        stack_overflow();
    }
    else {
        contents[top++] = i;
    }
}

int pop(void) {
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
    int op1, op2, re;

    printf("Enter an RPN expression: ");
    while ((ch=getchar())!='\n')
    {
        if (isdigit(ch))push(ch - '0');
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            if (is_empty())break;
            op2 = pop();
            op1 = pop();
            switch (ch)
            {
            case '+':re = op1 + op2; break;
            case '-':re = op1 - op2; break;
            case '*':re = op1 * op2; break;
            case '/':re = op1 / op2; break;
            default:
                break;
            }
            push(re);
        }
        else if(ch=='=')
        {
            printf("Value of expression: %d\n", pop());
            make_empty();
            printf("Enter an RPN expression: ");
        }
    }
}