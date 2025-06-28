#include <stdio.h>
#include <string.h>

typedef union
{
    int i;
    char c[25];
    // double d;/*最大对齐数是8*/

    int d;/*最大对齐数是4*/
} UNION;

int main()
{
    UNION u;
    // 同一时间只能初始化一个成员，所以只能想下面这样初始化！
    // 初始化成员 c
    strcpy(u.c, "hello");
    printf("u.c=%s\t", u.c);
    printf("Total Size=%zu\n",sizeof(u));

    // 初始化成员 i
    u.i = 123;
    printf("u.i=%d\t\t", u.i);
    printf("Total Size=%zu\n",sizeof(u));

    // 初始化成员 d
    u.d = 3.14;
    printf("u.d=%f\t", u.d);
    printf("Total Size=%zu\n",sizeof(u));

    return 0;
}