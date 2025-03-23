#include <stdio.h>
int main()
{
    printf("hello,world_printf!\n");

    char str[100]; // 这是在栈区分配的内存
    sprintf(str, "hello,world_sprintf!\n");
    printf("%s", str);
    char str1[100];

    snprintf(str1, 5, "%s",str);
    printf("%s\n", str1);
    fprintf(stdout, "hello,world_fprintf!\n");

    return 0;
}