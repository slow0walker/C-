#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <stdio.h>

struct point { int x, y; };
struct rectangle { struct point upper_left, lower_right; };

int main()
{
	struct rectangle* p = (struct rectangle*)malloc(sizeof(struct rectangle));
	if (p == NULL) {
		fprintf(stderr, "Memory allocation failed!\n");
		return 1;
	}
	p->upper_left.x = 10;
	p->upper_left.y = 25;
	p->lower_right.x = 20;
	p->lower_right.y = 15;
	return 0;
}

struct rectangle* create_rectangle(int x1, int y1, int x2, int y2)
{
	struct rectangle* p = malloc(sizeof(struct rectangle));
	if (!p) return NULL;
	p->upper_left.x = x1;
	p->upper_left.y = y1;
	p->lower_right.x = x2;
	p->lower_right.y = y2;
	return p;
}
