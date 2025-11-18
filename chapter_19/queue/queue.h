#define _CRT_SECURE_NO_WARNINGS 1
#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>
typedef struct queue* Queue; //不完整类型，其完整实现在.c文件

void queue_init(Queue q);
void queue_init_d(Queue q, int init_c);//动态数组分配时容量
void add_queue(Queue q, QueueElement value);
void delete_queue(Queue q);
QueueElement front(Queue q);
QueueElement rear(Queue q);
bool is_empty(Queue q);
void clear_queue(Queue q);
void destroy_queue(Queue q);
#endif 