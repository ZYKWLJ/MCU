/**
 * filename:test6.c
 * description: 测试宏在一键开关下的使用，非常便于调试！
 * author:EthanYankang
 * create time:2025/04/01 10:50:37
 */

#include "color.h"
#include <stdio.h>

#define DEBUG

#ifdef DEBUG
// 修正格式字符串拼接
#define LOG(format, ...) printf("%s[DEBUG] %s" format, GREEN, RESET ,__VA_ARGS__)
#else
#define LOG(format, ...)
#endif

int main()
{
    LOG("Error in file %s, line %d\n", __FILE__, __LINE__);//传入可变参数，需要使用__VA_ARGS__并加上逗号
    return 0;
}    