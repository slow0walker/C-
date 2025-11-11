#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
struct node {
	int value;
	struct node* next;
};

int count_occurrences(struct node* list, int n)
{
	struct node* p = list;
	int count = 0;
	while (p)
	{
		if (p->value == n)count++;
		 p= p->next;
	}
	return count;
}