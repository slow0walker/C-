#define _CRT_SECURE_NO_WARNINGS 1

//qsort(a + 50, 50, sizeof(int), compar);

#include <stdio.h>
#include <string.h>

// 定义结构体
typedef struct {
    char* cmd_name;
    void (*cmd_pointer)(void);
} FileCmd;

// 假设各功能函数已定义
void new_cmd(void) {
    printf("执行 new 命令\n");
}
void open_cmd(void) {
    printf("执行 open 命令\n");
}
void close_cmd(void) {
    printf("执行 close 命令\n");
}
void close_all_cmd(void) {
    printf("执行 close all 命令\n");
}
void save_cmd(void) {
    printf("执行 save 命令\n");
}
void save_as_cmd(void) {
    printf("执行 save as 命令\n");
}
void save_all_cmd(void) {
    printf("执行 save all 命令\n");
}
void print_cmd(void) {
    printf("执行 print 命令\n");
}
void exit_cmd(void) {
    printf("执行 exit 命令\n");
}

// 结构数组初始化
FileCmd file_cmd[] = {
    {"new", new_cmd},
    {"open", open_cmd},
    {"close", close_cmd},
    {"close all", close_all_cmd},
    {"save", save_cmd},
    {"save as", save_as_cmd},
    {"save all", save_all_cmd},
    {"print", print_cmd},
    {"exit", exit_cmd}
};

// 查找并执行匹配命令的函数
void execute_cmd(const char* cmd) {
    int i;
    int cmd_count = sizeof(file_cmd) / sizeof(file_cmd[0]);
    for (i = 0; i < cmd_count; i++) {
        if (strcmp(file_cmd[i].cmd_name, cmd) == 0) {
            file_cmd[i].cmd_pointer();
            return;
        }
    }
    printf("未找到匹配的命令: %s\n", cmd);
}

int main() {
    // 测试用例
    execute_cmd("new");
    execute_cmd("open");
    execute_cmd("save");
    execute_cmd("invalid_cmd");
    return 0;
}