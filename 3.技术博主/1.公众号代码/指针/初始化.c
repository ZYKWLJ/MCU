/**
 * filename:初始化.c
 * description: 指针的初始化方式
 * author:EthanYankang
 * create time:2025/04/02 23:17:28
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int (*op)(int,int);//定义函数指针类型
int add(int a,int b){
    return a+b;
}
int multi(int a,int b){
    return a*b;
}
void fun(int a,int b,op operation){//传入一个op功能！
    int c=operation(a,b);
    printf("%d\n",c);
}
int main()
{
    int a=10,b=10;
    fun(a,b,add);//实现1——传入加法
    fun(a,b,multi);//实现2——传入乘法
    return 0;
}