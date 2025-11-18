#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;

// 函数声明
int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void dump(const char* filename);
void restore(const char* filename);

int main(void) {
    char code;

    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n');  // 跳过换行符后的多余字符

        switch (code) {
        case 'd': {
            char filename[100];
            printf("Enter name of output file: ");
            scanf("%s", filename);
            dump(filename);
            break;
        }
        case 'r': {
            char filename[100];
            printf("Enter name of input file: ");
            scanf("%s", filename);
            restore(filename);
            break;
        }
        case 'i': insert(); break;
        case 's': search(); break;
        case 'u': update(); break;
        case 'p': print(); break;
        case 'q': return 0;
        default: printf("Illegal code\n");
        }
        printf("\n");
    }
}

// 转储（保存）数据库到文件
void dump(const char* filename) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Can't open %s\n", filename);
        return;
    }
    fwrite(&num_parts, sizeof(int), 1, fp);
    fwrite(inventory, sizeof(struct part), num_parts, fp);
    fclose(fp);
    printf("Database dumped to %s successfully.\n", filename);
}

// 从文件恢复数据库
void restore(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Can't open %s\n", filename);
        return;
    }
    fread(&num_parts, sizeof(int), 1, fp);
    fread(inventory, sizeof(struct part), num_parts, fp);
    fclose(fp);
    printf("Database restored from %s successfully.\n", filename);
}

int find_part(int number) {
    int i;
    for (i = 0; i < num_parts; i++)
        if (inventory[i].number == number)
            return i;
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
    scanf("%s", inventory[num_parts].name);
    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[num_parts].on_hand);
    num_parts++;
}

void search(void) {
    int i, number;
    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);
    if (i >= 0) {
        printf("Name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
    }
    else {
        printf("Part not found.\n");
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
    printf("Part Number\tPart Name\tQuantity on Hand\n");
    for (i = 0; i < num_parts; i++)
        printf("%d\t\t%s\t\t%d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
}