/**
 * filename:6.输出图像.c
 * description: 输出c的图像
 * author:EthanYankang
 * create time:2025/04/01 20:51:17
 */
#include <stdio.h>
int main()
{
    for (int i = 0; i < 4; i++)
    {
        if (i < 1 || i > 2)
        {
            printf("*****\n");
        }
        else
        {
            printf("*\n");
        }
    }
    return 0;
}