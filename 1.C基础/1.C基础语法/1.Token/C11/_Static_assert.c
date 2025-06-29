#include <stdio.h>
// 编译期检查条件，不满足则报错
_Static_assert(sizeof(int) == 4, "int's size must be 4B");
// _Static_assert(8 * sizeof(void *) == 64, "must run in 64 bits");
_Static_assert(8 * sizeof(void*) == 32, "must run in 32 bits");

int main()
{
    // 编译期已验证，运行时无需检查
    printf("env check passed!\n");
    return 0;
}