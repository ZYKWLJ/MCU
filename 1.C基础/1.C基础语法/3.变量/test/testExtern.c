#include <stdio.h>

// 函数外定义变量 x 和 y
int x;
int y;
int addtwonum()
{
    // 函数内声明变量 x 和 y 为外部变量
    extern int x;
    extern int y;
    // 给外部变量（全局变量）x 和 y 赋值
    x = 1;
    y = 2;
    return x + y;
}

int main()
{
    printf("x为: %d,y为: %d\n", x, y);

    int result;
    // 调用函数 addtwonum
    result = addtwonum();
    printf("result 为: %d\n", result);
    printf("x为: %d,y为: %d\n", x, y);//外部变量的值从此改变了
    return 0;
}