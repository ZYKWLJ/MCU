#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//定义函数指针类型
typedef int (*op)(int,int);
//函数指针具体实现1——add  
int add(int a,int b){
    return a+b;
}
//函数指针具体实现2——multi
int multi(int a,int b){
    return a*b;
}
//这里传入函数指针！
void fun(int a,int b,op operation){//传入一个op功能！
    int c=operation(a,b);
    printf("%d\n",c);
}
//测试
int main()
{
    int a=10,b=10;
    fun(a,b,add);//实现1——传入加法
    fun(a,b,multi);//实现2——传入乘法
    return 0;
}