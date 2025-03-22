#include <stdio.h>
#include <stdlib.h>
int a=1;
int main()
{
    void *p;
    int a1=1;
    char s[] = "hello world";
    int *p1 = (int *)malloc(sizeof(int));
    printf("sizeof(p) = %zu\naddress=%p\n", sizeof(p), p); // 输出 0x7fffffffd828，这显然是栈空间的地址
    //  x86 - 64 架构中，一般只会使用 48 位的虚拟地址，
    // 地址范围从 0x0000000000000000 到 0x00007fffffffffff 是用户空间，
    // 从 0xffff800000000000 到 0xffffffffffffffff 是内核空间。
    printf("sizeof(p) = %zu\naddress=%p\n", sizeof(p1), p1); 
    printf("sizeof(p) = %zu\naddress=%p\n", sizeof(a), &a); 
    printf("sizeof(p) = %zu\naddress=%p\n", sizeof(s), s); 
    printf("sizeof(p) = %zu\naddress=%p\n", sizeof(a1), &a1); 
    return 0;
}