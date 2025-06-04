#include <stdio.h>
#define CHAR_IO_
#define CHARS_IO_
#define FOMAT_CHAR_IO_
#define BINARY_CHAR_IO_
int main()
{
#ifdef CHAR_IO_
    printf("TEST char_io\n\n");
    {
        char ch;
        ch = getchar();
        putchar(ch);
        printf("\n");
    }
    {
        FILE *fp;
        fp = fopen("/home/eyk/桌面/MCU/2.知识卡片/字符串/char_io.txt", "w+");
        if (fp == NULL)
        {
            perror("fopen failed");
        }
        else
        {
            fputc('a', fp);
        }
        char ch;
        rewind(fp); // 记得一定要置位为0
        while ((ch = fgetc(fp)) != EOF)
        {
            putchar(ch);
        }

        fclose(fp);
    }
#endif

#ifdef CHARS_IO_
    printf("TEST chars_io\n\n");
    {
        char dest[20] = {0};
        fgets(dest, 20, stdin); // 会连着读取换行符
        printf("%s\n", dest);
        puts("hello world");
    }
    printf("TEST FILE_IO\n\n");
    {
        FILE *fp = fopen("/home/eyk/桌面/MCU/2.知识卡片/字符串/char_io.txt", "w+");
        if (fp == NULL)
        {
            perror("fopen failed");
        }
        else
        {
            fputs("hello world", fp);
            rewind(fp);
            char dest[20] = {0};
            fgets(dest, 20, fp);
            printf("%s\n", dest);
        }
    }
#endif

#ifdef FOMAT_CHAR_IO_
    printf("TEST FOMAT_CHAR_IO\n\n");
    {
        char dest[20] = {0};
        scanf("%s", dest);
        dest[3] = '\0';
        printf("%s\n", dest);
    }
    printf("TEST FILE_IO\n\n");
    {
        FILE *fp = fopen("/home/eyk/桌面/MCU/2.知识卡片/字符串/char_io.txt", "w+");
        if (fp == NULL)
        {
            perror("fopen failed");
        }
        else
        {
            char dest[20] = {0};
            fprintf(fp, "%s", "hello world");
            rewind(fp); // 记得一定要置位为0
            fscanf(fp, "%s", dest);
            printf("%s\n", dest);
        }
    }
    printf("TEST FOMAT_CHAR_IO\n\n");
    {
        char dest[20] = {0};
        char src[20] = {0};
        int a = 100;
        // 假设给dest赋一个初始值，方便测试
        sprintf(dest, "hello"); // 赋值方向<-
        // 从dest读取内容到src
        sscanf(dest, "%s", src); // 赋值方向->
        printf("%s\n", src);
        // 将dest和a的值格式化到dest中
        sprintf(dest, "%s_%d\n", src, a); // 赋值方向<-
        printf("%s\n", dest);
    }

#endif
#ifdef BINARY_CHAR_IO_
    printf("TEST BINARY_CHAR_IO\n\n");
    {
        char dest[20] = {0};
        sprintf(dest, "hello\nworld"); // 多用函数来实现赋值！
        FILE *fp = fopen("/home/eyk/桌面/MCU/2.知识卡片/字符串/char_io.txt", "w+");
        if (fp == NULL)
        {
            perror("fopen failed");
        }
        else
        {
            fwrite(dest, sizeof(char), 11, fp);
            rewind(fp);
            char dest1[20] = {0};
            fread(dest1, sizeof(char), 11, fp);
            printf("%s\n", dest1);
        }
    }
#endif
}