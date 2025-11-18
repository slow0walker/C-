#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "queue.h"
#include<stdlib.h>
typedef int QueueElement;

typedef struct queue {
    QueueElement* data; // 动态数组指针
    int capacity;       // 当前容量
    int front;          // 队头索引
    int rear;           // 队尾索引
    int size;           // 当前元素个数
};

void queue_init(Queue q, int initial_capacity) {
    if (initial_capacity <= 0)
        initial_capacity = 4; // 默认最小容量

    q->data = (QueueElement*)malloc(sizeof(QueueElement) * initial_capacity);
    if (!q->data) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    q->capacity = initial_capacity;
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

// 判断是否为空
bool is_empty(Queue q) {
    return q->size == 0;
}

// 扩容函数（当队列满时）
static void expand_queue(Queue q) {
    int new_capacity = q->capacity * 2;
    QueueElement* new_data = (QueueElement*)malloc(sizeof(QueueElement) * new_capacity);
    if (!new_data) {
        printf("Memory allocation failed during resize!\n");
        exit(1);
    }

    // 按顺序复制旧数据（考虑循环队列）
    for (int i = 0; i < q->size; i++) {
        new_data[i] = q->data[(q->front + i) % q->capacity];
    }

    free(q->data);
    q->data = new_data;
    q->capacity = new_capacity;
    q->front = 0;
    q->rear = q->size - 1;
}

// 入队
void add_queue(Queue q, QueueElement value) {
    if (q->size == q->capacity) {
        expand_queue(q);
    }

    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = value;
    q->size++;
}

// 出队
void delete_queue(Queue q) {
    if (is_empty(q)) {
        printf("Queue underflow!\n");
        return;
    }
    q->front = (q->front + 1) % q->capacity;
    q->size--;
}

// 获取队头元素
QueueElement front(Queue q) {
    if (is_empty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->data[q->front];
}

// 获取队尾元素
QueueElement rear(Queue q) {
    if (is_empty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->data[q->rear];
}

// 清空队列（不释放内存）
void clear_queue(Queue q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

// 销毁队列（释放内存）
void destroy_queue(Queue q) {
    if (q->data) {
        free(q->data);
        q->data = NULL;
    }
    q->capacity = q->front = q->rear = q->size = 0;
}