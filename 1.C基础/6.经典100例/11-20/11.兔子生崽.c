/**
 * filename:11.兔子生崽.c
 * description: 有一对兔子，从出生后第3个月起每个月都生一对兔子，小兔子长到第三个月后每个月又生一对兔子，假如兔子都不死，问每个月的兔子总数为多少？
 * author:EthanYankang
 * create time:2025/04/02 18:40:25
 */
#include <stdio.h>
int main()
{
    int a = 1, b = 1, c = 0;
    for (int i = 0; i < 40; i++)
    {
        c = a + b;
        a = b;
        b = c;
        printf("第%d个月生崽:%d\n", i, c);
    }
    return 0;
}