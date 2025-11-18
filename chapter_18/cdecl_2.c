#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXTOKENS 100
#define MAXTOKENLEN 64

enum type_tag { IDENTIFIER, QUALIFIER, TYPE };

struct token {
    int type;
    char string[MAXTOKENLEN];
};

int top = -1;
struct token stack[MAXTOKENS];
struct token this;

#define POP() (stack[top--])
#define PUSH(t) (stack[++top] = (t))

//enum type_tag classify_string(void)
//{
//    char* s = this.string;
//    if (strcmp(s, "const") == 0) {
//        strcpy(this.string, "read-only");
//        return QUALIFIER;
//    }
//    if (strcmp(s, "volatile") == 0) return QUALIFIER;
//    if (!strcmp(s, "void") || !strcmp(s, "char") || !strcmp(s, "int") ||
//        !strcmp(s, "short") || !strcmp(s, "long") || !strcmp(s, "float") ||
//        !strcmp(s, "double") || !strcmp(s, "signed") || !strcmp(s, "unsigned") ||
//        !strcmp(s, "struct") || !strcmp(s, "union") || !strcmp(s, "enum"))
//        return TYPE;
//    return IDENTIFIER;
//}

enum type_tag classify_string(void)
{
    char* s = this.string;

    if (strcmp(s, "const") == 0) {
        /* 安全替换 */
        snprintf(this.string, MAXTOKENLEN, "read-only");
        return QUALIFIER;
    }
    if (strcmp(s, "volatile") == 0)
        return QUALIFIER;

    /* 关键字表：更易维护，便于扩展或加入 typedef 表查找 */
    static const char* types[] = {
        "void","char","signed","unsigned","int","short","long",
        "float","double","struct","union","enum", NULL
    };
    for (const char** p = types; *p != NULL; ++p) {
        if (strcmp(s, *p) == 0) return TYPE;
    }

    /* 仍可在这里查 typedef 符号表（若实现了符号表） */

    return IDENTIFIER;
}

//void gettoken(void)
//{
//    int c;
//    char* p = this.string;
//
//    /* 跳过空白 */
//    while ((c = getchar()) == ' ' || c == '\t')
//        ;
//
//    if (c == EOF) {
//        this.type = EOF;
//        return;
//    }
//
//    if (isalnum(c) || c == '_') {
//        *p++ = c;
//        while (isalnum(c = getchar()) || c == '_')
//            *p++ = c;
//        *p = '\0';
//        ungetc(c, stdin);
//        this.type = classify_string();
//        return;
//    }
//
//    if (c == '*') {
//        strcpy(this.string, "pointer to");
//        this.type = '*';
//        return;
//    }
//
//    /* 单字符 token */
//    this.string[0] = (char)c;
//    this.string[1] = '\0';
//    this.type = c;
//}


void gettoken(void)
{
    int c;
    char* p = this.string;
    size_t maxlen = MAXTOKENLEN - 1; // 留 1 字节给 '\0'
    size_t len = 0;

    /* 跳过空格和制表，但不跳过换行（按需修改） */
    while ((c = getchar()) == ' ' || c == '\t')
        ;

    if (c == EOF || c == '\n') {
        this.type = EOF;
        this.string[0] = '\0';
        return;
    }

    if (isalnum((unsigned char)c) || c == '_') {
        /* 首字符 */
        if (len < maxlen) {
            *p++ = (char)c;
            len++;
        }
        /* 读随后的字符 */
        while (1) {
            c = getchar();
            if (c == EOF) break;
            if (!(isalnum((unsigned char)c) || c == '_')) break;
            if (len < maxlen) {
                *p++ = (char)c;
                len++;
            }
            /* else 忽略超长字符但继续读取直到 token 结束 */
        }
        *p = '\0';
        if (c != EOF) ungetc(c, stdin);  /* 只有非 EOF 才放回 */
        this.type = classify_string();
        return;
    }

    if (c == '*') {
        /* 安全写入 */
        snprintf(this.string, MAXTOKENLEN, "pointer to");
        this.type = '*';
        return;
    }

    /* 单字符 token */
    this.string[0] = (char)c;
    this.string[1] = '\0';
    this.type = c;
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
        gettoken();
    }
}

void deal_with_arrays(void)
{
    while (this.type == '[') {
        gettoken();
        if (isdigit(this.string[0])) {
            printf("array %d of ", atoi(this.string));
            gettoken(); // 跳过数字
        }
        else {
            printf("array of ");
        }
        gettoken(); // 跳过 ']'
    }
}

void deal_with_function_args(void)
{
    if (this.type == '(') {
        int paren = 1;
        while (paren > 0) {
            gettoken();
            if (this.type == '(') paren++;
            else if (this.type == ')') paren--;
        }
        gettoken(); // 下一个 token
        printf("function returning ");
    }
}

void deal_with_pointers(void)
{
    while (top >= 0 && stack[top].type == '*') {
        struct token t = POP();
        printf("%s ", t.string);
    }
}

void deal_with_declarator(void)
{
    if (this.type == '[')
        deal_with_arrays();
    else if (this.type == '(')
        deal_with_function_args();

    deal_with_pointers();

    while (top >= 0) {
        if (stack[top].type == '(') {
            POP();
            gettoken();
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
    while (!feof(stdin)) {
        top = -1;
        read_to_first_identifier();
        if (this.type == EOF) break;
        deal_with_declarator();
        printf("\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
    }
    return 0;
}
