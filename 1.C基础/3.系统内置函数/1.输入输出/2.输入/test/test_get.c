#include <stdio.h>
#include <string.h>
int main()
{
    printf("test_getchar():\n");
    char c = getchar();
    printf("c=%c\n", c);

    printf("\ntest_getc():\n");
    char d = getc(stdin);
    printf("d=%c\n", d);



    printf("\ntest_fgets():\n");//从文件中读取字符串，并返回字符串！
    // char*e = gets();# 已经被弃用
    char e[100];
    char f[100];
    // 使用 fgets 读取字符串到数组 e 中
    if (fgets(e, sizeof(e), stdin) != NULL) {
        // 去除换行符
        e[strcspn(e, "\n")] = '\0';

        // 将数组 e 中的内容复制到数组 f 中，可以使用 strcpy 函数
        strcpy(f, e);

        // 输出数组 f 的内容
        printf("数组 f 的内容是: %s\n", f);
    }
    printf("e=%s\n", e);
    return 0;
}