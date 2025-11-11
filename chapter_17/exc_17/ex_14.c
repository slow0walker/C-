#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
struct node {
	int value;
	struct node* next;
};
void delete_from_list(struct node** list,int n)
{
	if (*list == NULL)return;
	struct node* cur = *list;
	struct node* prev = NULL;
	while (cur!=NULL&&cur->value!=n)
	{
		prev = cur;
		cur = cur->next;
	}
	if (cur == NULL)
	{
		return;
	}
	if (prev == NULL)
	{
		*list = cur->next;
	}
	else
	{
		prev->next = cur->next;
	}
	free(cur);
}
