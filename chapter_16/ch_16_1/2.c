#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void sort_by_number(void); // 新增排序函数

int main() {
    char code;

    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n');
        switch (code) {
        case 'i': insert(); break;
        case 's': search(); break;
        case 'u': update(); break;
        case 'p':
            sort_by_number(); // 打印前先排序
            print();
            break;
        case 'q': return 0;
        default: printf("Illegal code\n");
        }
        printf("\n");
    }
}

// 新增：按零件编号冒泡排序
void sort_by_number(void) {
    int i, j;
    struct part temp;
    for (i = 0; i < num_parts - 1; i++) {
        for (j = 0; j < num_parts - 1 - i; j++) {
            if (inventory[j].number > inventory[j + 1].number) {
                temp = inventory[j];
                inventory[j] = inventory[j + 1];
                inventory[j + 1] = temp;
            }
        }
    }
}

// 其余函数（find_part、insert、search、update）保持不变
void print(void) {
    int i;
    printf("Part Number  Part Name        Quantity on Hand\n");
    for (i = 0; i < num_parts; i++)
        printf("%7d  %-25s%11d\n", inventory[i].number,
            inventory[i].name, inventory[i].on_hand);
}