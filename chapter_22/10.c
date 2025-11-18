#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 25

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    struct part* next;
};

struct part* inventory = NULL;

// 函数声明
void dump(const char* filename);
void restore(const char* filename);
struct part* find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

int main(void) {
    char code;

    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n');

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
        case 'q':
            // 释放链表内存（可选）
            struct part* curr, * temp;
            curr = inventory;
            while (curr != NULL) {
                temp = curr;
                curr = curr->next;
                free(temp);
            }
            return 0;
        default: printf("Illegal code\n");
        }
        printf("\n");
    }
}

void dump(const char* filename) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Can't open %s\n", filename);
        return;
    }
    struct part* curr = inventory;
    while (curr != NULL) {
        fwrite(&curr->number, sizeof(int), 1, fp);
        fwrite(curr->name, sizeof(char), NAME_LEN + 1, fp);
        fwrite(&curr->on_hand, sizeof(int), 1, fp);
        curr = curr->next;
    }
    fclose(fp);
    printf("Database dumped to %s successfully.\n", filename);
}

void restore(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Can't open %s\n", filename);
        return;
    }
    // 先释放原有链表
    struct part* curr, * temp;
    curr = inventory;
    while (curr != NULL) {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
    inventory = NULL;

    struct part* last = NULL;
    int number, on_hand;
    char name[NAME_LEN + 1];
    while (fread(&number, sizeof(int), 1, fp) == 1 &&
        fread(name, sizeof(char), NAME_LEN + 1, fp) == NAME_LEN + 1 &&
        fread(&on_hand, sizeof(int), 1, fp) == 1) {
        struct part* new_part = (struct part*)malloc(sizeof(struct part));
        if (new_part == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            fclose(fp);
            // 清理已分配的部分链表（可选）
            curr = inventory;
            while (curr != NULL) {
                temp = curr;
                curr = curr->next;
                free(temp);
            }
            inventory = NULL;
            exit(EXIT_FAILURE);
        }
        new_part->number = number;
        strcpy(new_part->name, name);
        new_part->on_hand = on_hand;
        new_part->next = NULL;

        if (inventory == NULL) {
            inventory = new_part;
        }
        else {
            last->next = new_part;
        }
        last = new_part;
    }
    fclose(fp);
    printf("Database restored from %s successfully.\n", filename);
}

struct part* find_part(int number) {
    struct part* curr = inventory;
    while (curr != NULL && curr->number != number) {
        curr = curr->next;
    }
    return curr;
}

void insert(void) {
    struct part* new_part, * curr, * prev;
    new_part = (struct part*)malloc(sizeof(struct part));
    if (new_part == NULL) {
        printf("Database is full; can't add more parts.\n");
        return;
    }
    printf("Enter part number: ");
    scanf("%d", &new_part->number);
    prev = NULL;
    curr = inventory;
    while (curr != NULL && curr->number < new_part->number) {
        prev = curr;
        curr = curr->next;
    }
    if (curr != NULL && curr->number == new_part->number) {
        printf("Part already exists.\n");
        free(new_part);
        return;
    }
    printf("Enter part name: ");
    scanf("%s", new_part->name);
    printf("Enter quantity on hand: ");
    scanf("%d", &new_part->on_hand);
    new_part->next = curr;
    if (prev == NULL) {
        inventory = new_part;
    }
    else {
        prev->next = new_part;
    }
}

void search(void) {
    int number;
    struct part* curr;
    printf("Enter part number: ");
    scanf("%d", &number);
    curr = find_part(number);
    if (curr != NULL) {
        printf("Name: %s\n", curr->name);
        printf("Quantity on hand: %d\n", curr->on_hand);
    }
    else {
        printf("Part not found.\n");
    }
}

void update(void) {
    int number, change;
    struct part* curr;
    printf("Enter part number: ");
    scanf("%d", &number);
    curr = find_part(number);
    if (curr != NULL) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        curr->on_hand += change;
    }
    else {
        printf("Part not found.\n");
    }
}

void print(void) {
    struct part* curr = inventory;
    printf("Part Number\tPart Name\tQuantity on Hand\n");
    while (curr != NULL) {
        printf("%d\t\t%s\t\t%d\n", curr->number, curr->name, curr->on_hand);
        curr = curr->next;
    }
}