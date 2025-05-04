#include <stdio.h>
#include <string.h>

typedef union
{
    int i;
    char c[25];
    // double d;/*最大对齐数是8*/
    double d; /*最大对齐数是4*/
} UNION;

int main()
{
    UNION u;
    // 同一时间只能初始化一个成员，所以只能想下面这样初始化！
    // 初始化成员 c
    strcpy(u.c, "hello");
    printf("u.c=%s\t", u.c);
    printf("u.i=%d\t", u.i);
    printf("u.d=%lf\t", u.d);
    printf("Total Size=%zu\n", sizeof(u));

    // 初始化成员 i
    u.i = 123;
    printf("u.c=%s\t", u.c);
    printf("u.i=%d\t", u.i);
    printf("u.d=%lf\t", u.d);
    printf("Total Size=%zu\n", sizeof(u));

    // 初始化成员 d
    u.d = 3.14;
    printf("u.c=%s\t", u.c);
    printf("u.i=%d\t", u.i);
    printf("u.d=%lf\t", u.d);
    printf("Total Size=%zu\n", sizeof(u));

    return 0;
}

/*
以下结果充分证明了共用体的特点：
同一时间只能初始化一个成员，其他的会被覆盖！乱码！
$ /home/eyk/桌面/MCU/1.C基础/2.高级数据类型/4.共用体/test/test
u.c=hello       u.i=1819043176  u.d=0.000000    Total Size=32
u.c={   u.i=123 u.d=0.000000    Total Size=32
u.c=��Q�        @       u.i=1374389535  u.d=3.140000    Total Size=32*/