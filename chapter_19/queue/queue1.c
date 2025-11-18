#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "queue.h"

typedef int QueueElement;
#define MAX_QUEUE_SIZE 100
//用定长数组实现队列
 struct queue {
	QueueElement data[MAX_QUEUE_SIZE];
	int front;
	int rear;
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
	q->front = 0;
	q->rear = -1;
	q->size = 0;
}

bool is_empty(Queue q)
{
	return q->size == 0;
}

//向队列添加元素
void add_queue(Queue q,QueueElement value)
{
	if (q->size == MAX_QUEUE_SIZE)
	{
		terminate("Queue if full!");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = value;
	++q->size;
}

void delete_queue(Queue q)
{
	if (is_empty(q))
	{
		terminate("Queue is empty!");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	--q->size;
}

QueueElement front(Queue q)
{
	if (is_empty(q))
	{
		terminate("Queue is empty!");
	}
	return q->data[q->front];
}

QueueElement rear(Queue q)
{
	if (is_empty(q))
	{
		terminate("Queue is empty!");
	}
	return q->data[q->rear];
}