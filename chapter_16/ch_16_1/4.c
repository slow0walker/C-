#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    double price; // 新增价格成员
} inventory[MAX_PARTS];

int num_parts = 0;

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void modify_price(void); // 新增修改价格函数

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
        case 'p': print(); break;
        case 'm': modify_price(); break; // 新增修改价格命令
        case 'q': return 0;
        default: printf("Illegal code\n");
        }
        printf("\n");
    }
}

int find_part(int number) {
    int i;
    for (i = 0; i < num_parts; i++) {
        if (inventory[i].number == number)
            return i;
    }
    return -1;
}

void insert(void) {
    int part_number;
    if (num_parts == MAX_PARTS) {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);

    if (find_part(part_number) >= 0) {
        printf("Part already exists.\n");
        return;
    }

    inventory[num_parts].number = part_number;
    printf("Enter part name: ");
    read_line(inventory[num_parts].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[num_parts].on_hand);
    printf("Enter price: "); // 新增输入价格
    scanf("%lf", &inventory[num_parts].price);
    num_parts++;
}

void search(void) {
    int i, number;
    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);
    if (i >= 0) {
        printf("Part name: %s\n", inventory[i].name);
        printf("quantity on hand: %d\n", inventory[i].on_hand);
        printf("Price: %.2f\n", inventory[i].price); // 显示价格
    }
    else {
        printf("part not found.\n");
    }
}

void update(void) {
    int i, number, change;
    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);
    if (i >= 0) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    }
    else {
        printf("Part not found.\n");
    }
}

void print(void) {
    int i;
    printf("Part Number  Part Name        Quantity on Hand  Price\n");
    for (i = 0; i < num_parts; i++)
        printf("%7d  %-25s%11d  %7.2f\n", inventory[i].number,
            inventory[i].name, inventory[i].on_hand, inventory[i].price);
}

void modify_price(void) {
    int i, number;
    double new_price;
    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);
    if (i >= 0) {
        printf("Enter new price: ");
        scanf("%lf", &new_price);
        inventory[i].price = new_price;
        printf("Price updated successfully.\n");
    }
    else {
        printf("Part not found.\n");
    }
}