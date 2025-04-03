/**
* filename:3.完全平方数求数.c
* description:
题目：一个正整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？

分析：完全平方数的性质就是i*i=n，其中i<=n/2即可！
x+100=i*i
x+100+168=j*j
x=i*i-100(i>10)

i*i=j*j-168;
i<j;
直接使用暴力循环即可！找到退出！
* author:EthanYankang
* create time:2025/03/29 21:15:08
*/

#include <stdio.h>
int main()
{
    for (int j = 11;; j++)
    {
        for (int i = 11; i < j; i++)
        {
            if (i * i == j * j - 168)
            {
                printf("x=%d\n", i * i - 100);
            }
        }
    }
    return 0;
}