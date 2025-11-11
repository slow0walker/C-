#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// 定义节点结构
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 定义栈结构
typedef struct Stack {
    Node* top;  // 指向栈顶节点
} Stack;

// 初始化栈
void init(Stack* s) {
    s->top = NULL;
}

// 判空
int is_empty(Stack* s) {
    return s->top == NULL;
}

// 入栈
void push(Stack* s, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    new_node->data = value;
    new_node->next = s->top; // 新节点指向原栈顶
    s->top = new_node;       // 更新栈顶
}

// 出栈
int pop(Stack* s) {
    if (is_empty(s)) {
        fprintf(stderr, "Error: Stack is empty!\n");
        exit(1);
    }
    Node* temp = s->top;                                            
    int value = temp->data;
    s->top = temp->next;
    free(temp);
    return value;
}

// 查看栈顶元素
int peek(Stack* s) {
    if (is_empty(s)) {
        fprintf(stderr, "Error: Stack is empty!\n");
        exit(1);
    }
    return s->top->data;
}

// 清空栈
void clear(Stack* s) {
    while (!is_empty(s)) {
        pop(s);
    }
}

// 打印栈内容（仅用于测试）
void print_stack(Stack* s) {
    Node* p = s->top;
    printf("Stack (top → bottom): ");
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

