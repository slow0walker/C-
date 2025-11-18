#define _CRT_SECURE_NO_WARNINGS 1
#ifndef STACK_H
#define STACK_H
#include<stdbool.h>

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);

#endif // !STACK_H
