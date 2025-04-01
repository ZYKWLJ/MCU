/**
* filename:test4.c
* description:测试编译器自带的宏，主要是函数和 行号
* author:EthanYankang
* create time:2025/04/01 10:26:28
*/
#include <stdio.h>

void log_message() {
    printf("文件名: %s\n", __FILE__);     // 当前文件的名称
    printf("当前行号: %d\n", __LINE__);   // 当前行的行号
    printf("编译日期: %s\n", __DATE__);   // 编译的日期
    printf("编译时间: %s\n", __TIME__);   // 编译的时间
    printf("函数名: %s\n", __func__);     // 当前函数的名称（C99新增）
}

int main() {
    log_message();
    return 0;
}