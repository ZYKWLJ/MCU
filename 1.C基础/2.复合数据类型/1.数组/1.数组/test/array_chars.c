#include <stdio.h>

int main(void)
{
    /**
     * data descp: 本质是数组，编译器确定的内存区域，是不可变的左值
     */
    char char1[6] = "hello";
    char1 = "Ethan";
    /**
     * data descp: 本质是指针，是可变的左值，指向内存区域为代码段的.rodata
     */
    char *char2 = "world";
    char2 = "Ethan";
    return 0;
}