#define _CRT_SECURE_NO_WARNINGS 1
/* decl_to_words.c  — 简化的 C 声明到英语描述转换器 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXTOKENS 100
#define MAXTOKENLEN 64

enum type_tag { IDENTIFIER, QUALIFIER, TYPE };

struct token {
    int type; /* 可以是 IDENTIFIER/QUALIFIER/TYPE 或字符 '[', '(', '*' 等 */
    char string[MAXTOKENLEN];
};

int top = -1;
struct token stack[MAXTOKENS];
struct token this;

#define POP() (stack[top--])
#define PUSH(t) (stack[++top] = (t))

enum type_tag classify_string(void)
{
    char* s = this.string;
    if (strcmp(s, "const") == 0) {
        strcpy(this.string, "read-only");
        return QUALIFIER;
    }
    if (strcmp(s, "volatile") == 0) return QUALIFIER;
    if (strcmp(s, "void") == 0) return TYPE;
    if (strcmp(s, "char") == 0) return TYPE;
    if (strcmp(s, "signed") == 0) return TYPE;
    if (strcmp(s, "unsigned") == 0) return TYPE;
    if (strcmp(s, "int") == 0) return TYPE;
    if (strcmp(s, "short") == 0) return TYPE;
    if (strcmp(s, "long") == 0) return TYPE;
    if (strcmp(s, "float") == 0) return TYPE;
    if (strcmp(s, "double") == 0) return TYPE;
    if (strcmp(s, "struct") == 0) return TYPE;
    if (strcmp(s, "union") == 0) return TYPE;
    if (strcmp(s, "enum") == 0) return TYPE;
    return IDENTIFIER;
}

void gettoken(void)
{
    int c;
    char* p = this.string;

    /* skip spaces */
    while ((c = getchar()) == ' ' || c == '\t' || c == '\n')
        ;

    if (c == EOF) {
        this.type = EOF;
        this.string[0] = '\0';
        return;
    }

    if (isalnum(c)) {
        *p++ = c;
        while (isalnum(c = getchar()) || c == '_') { /* allow underscore in identifiers */
            *p++ = c;
        }
        ungetc(c, stdin);
        *p = '\0';
        this.type = classify_string();
        return;
    }

    if (c == '*') {
        strcpy(this.string, "pointer to");
        this.type = '*';
        return;
    }

    /* other single-char tokens like '(', ')', '[', ']' */
    this.string[0] = (char)c;
    this.string[1] = '\0';
    this.type = c;
    return;
}

void read_to_first_identifier(void)
{
    gettoken();
    while (this.type != IDENTIFIER && this.type != EOF) {
        PUSH(this);
        gettoken();
    }
    if (this.type == IDENTIFIER) {
        printf("%s is ", this.string);
        gettoken(); /* read next token for declarator processing */
    }
    else {
        printf("No identifier found.\n");
    }
}

void deal_with_arrays(void)
{
    while (this.type == '[') {
        /* read number if present */
        gettoken(); /* read token inside [ ... ] */
        if (isdigit((unsigned char)this.string[0])) {
            printf("array 0..%d ", atoi(this.string) - 1);
            gettoken(); /* read closing ']' */
        }
        else {
            /* unspecified size */
            printf("array of ");
        }
        gettoken(); /* move past ']' or next token */
        printf("of ");
    }
}

void deal_with_function_args(void)
{
    while (this.type == '(') {
        /* skip function arguments simplistically */
        while (this.type != ')' && this.type != EOF) {
            gettoken();
        }
        gettoken(); /* move past ')' */
        printf("function returning ");
    }
}

/* pop pointer tokens and print them (pointer tokens stored as '*' with string "pointer to") */
void deal_with_pointers(void)
{
    while (top >= 0 && stack[top].type == '*') {
        struct token t = POP();
        printf("%s ", t.string);
    }
}

void deal_with_declarator(void)
{
    if (this.type == '[') {
        deal_with_arrays();
    }
    else if (this.type == '(') {
        deal_with_function_args();
    }
    deal_with_pointers();

    while (top >= 0) {
        if (stack[top].type == '(') {
            POP();          /* remove '(' */
            gettoken();     /* read token after '(' */
            deal_with_declarator();
        }
        else {
            struct token t = POP();
            printf("%s ", t.string);
        }
    }
}

int main(void)
{
    printf("Enter a C declaration (single line), Ctrl+D to quit:\n");
    while (1) {
        top = -1;
        if (feof(stdin)) break;
        read_to_first_identifier();
        if (this.type == EOF) break;
        deal_with_declarator();
        printf("\n");
        /* skip to end of line for next declaration */
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        if (c == EOF) break;
    }
    return 0;
}
