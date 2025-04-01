/**
 * filename:test5.c
 * description:可变参数宏，专用于日志调试！
 * author:EthanYankang
 * create time:2025/04/01 10:30:31
 */
#include <stdio.h>
#include "color.h"
#define DEBUG_LOG(format, ...) printf("%s[DEBUG] %s" format , GREEN, RESET ,__VA_ARGS__)
// 上面的宏定义DEBUG部分是固定的，他的个格式化在后面的两个颜色宏。format占位符号对应后面的__VA_ARGS__，其代表可变参数
int main()
{
    DEBUG_LOG("Error in file %s, line %d: func:%s\t%s\n", __FILE__, __LINE__,__func__, "Something went wrong");
    return 0;
}