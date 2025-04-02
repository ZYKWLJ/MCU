/**
 * filename:12.101-200所有素数.c
 * description:
 * author:EthanYankang
 * create time:2025/04/02 18:44:53
 */
#include <stdio.h>
int help(int num)
{
    for (int i = 2; i < num / 2; i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int i, j;
    for (int i = 101; i <= 200; i++)
    {
        if (help(i))
            printf("%d\n", i);
    }
    return 0;
}
