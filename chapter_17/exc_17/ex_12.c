#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
struct node {
	int value;
	struct node* next;
};

struct node* find_last(struct node* list, int n)
{
	struct node* p =list;
	struct node* last = NULL;
	while (p)
	{
		if (p->value == n)
		{
			last = p;
		}
		p = p->next;
	}
	return last;
}