#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>

struct node {
	int value;
	struct node* next;
};

struct node* delete_from_list(struct node* list, int n)
{
	struct node** p=&list;
	while (*p != NULL & (*p)->value != n)
	{
		p = &((*p)->next);
	}
	if (*p != NULL)
	{
		struct node* temp = *p;
		*p = (*p)->next;
		free(temp);
	}
	return list;
}