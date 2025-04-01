/**
 * filename:test1.c
 * description:测试宏的替换与含参
 * author:EthanYankang
 * create time:2025/04/01 09:44:22
 */
#define SIZE 10
#define JUDUG_ARR_LENGTH(ARR)                     \
    do                                            \
    {                                             \
        if (sizeof(ARR) / sizeof(ARR[0]) == SIZE) \
        {                                         \
            printf("数组已满");                   \
        }                                         \
        else                                      \
        {                                         \
            printf("数组未满");                   \
        }                                         \
    } while (0)
// 这里的do while(0)是宏定义函数的一种常用方法！最好记住！
#include <stdio.h>
int main()
{
    int a = 10;
    int arr[SIZE-1] = {0};
    JUDUG_ARR_LENGTH(arr);
    return 0;
}