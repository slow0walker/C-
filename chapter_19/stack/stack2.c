#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// 定义链表节点结构
struct node {
    int data;
    struct node* next;
};

static struct node* top = NULL;

static void terminate(const char* message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

void make_empty(void)
{
    while (!is_empty())
        pop();
}

bool is_empty(void)
{
    return top == NULL;
}

bool is_full(void)
{
    return false;
}


void push(int i)
{
    // 分配新节点内存
    struct node* new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Error in push: stack is full."); 


    new_node->data = i;
    new_node->next = top;
    top = new_node;
}


int pop(void)
{
    struct node* old_top;
    int i;

    if (is_empty())
        terminate("Error in pop: stack is empty.");

    old_top = top;
    i = top->data;
    top = top->next;
    free(old_top);

    return i;
}