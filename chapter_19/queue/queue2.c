#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "queue.h"
#include<stdlib.h>
typedef int QueueElement;

typedef struct node {
	QueueElement data;
	struct node* next;
};

struct queue {
	struct node* front;
	struct node* rear;
	int size;
};

static void terminate(const char* msg)
{
	printf("%s\n", msg);
	exit(1);
}
//初始化
void queue_init(Queue q)
{
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}
//判断是否为空
bool is_empty(Queue q)
{
	return q->front == NULL;
}
//入队
void add_queue(Queue q, QueueElement value)
{
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	if (!new_node)terminate("Memory allocation failed!");

	new_node->data = value;
	new_node->next = NULL;

	if (is_empty(q))
	{
		q->front = q->rear = new_node;
	}
	else
	{
		q->rear->next = new_node;
		q->rear = new_node;
	}
	q->size++;
}
//出队
void delete_queue(Queue q)
{
	if (is_empty(q))terminate("Queue is empty!");
	struct node* temp = q->front;
	q->front = q->front->next;
	free(temp);

	if (q->front == NULL)q->rear = NULL;
	q->size--;
}
// 获取队头元素
QueueElement front(Queue q)
{
	if (is_empty(q))terminate("Queue is empty");
	return q->front->data;
}
// 获取队尾元素
QueueElement rear(Queue q)
{
	if (is_empty(q))terminate("Queue is empty");
	return q->rear->data;
}

void clear_queue(Queue q)
{
	while (!is_empty(q))
		delete_queue(q);
}

