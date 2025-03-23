#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("程序名称:\n %s\n\n", argv[0]);
    puts("命令行参数:");
    if (argc > 1)
    {
        printf("命令行提供的参数个数: %d\n", argc);
        printf("命令行提供的参数为:\n");
        for (int i = 1; i < argc; i++)
        {
            puts(argv[i]);
        }
    }
    else
    {
        printf("命令行没有提供额外参数.\n");
    }
}