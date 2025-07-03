#include <stdio.h>
typedef void (*funcPtr)();
void print()
{
    printf("hello\n");
}
int main(void)
{
    funcPtr p = print; // 或者&print也可以
    // 函数名和数组名一样，都是代表着这块内存区域的地址，所以加不加&是一样的意思。
    // 所以调用这个函数指针就有两种方法
    p();
    (*p)();
    // 原函数调用也有两种方法
    print();
    (*print)();
    // 下面打印出来的地址全一样的
    printf("%p\n", p);
    printf("%p\n", *p);
    printf("%p\n", print);
    printf("%p\n", &print);
    return 0;
}