#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef const char *string;
int main(int argc, char *argv[])
{
    FILE *fp = fopen("/home/eyk/桌面/MCU/1.C基础/3.Unix系统其他特点/5.文件处理/test/file_a.txt", "w+");
    if (fp == NULL)
    {
        perror("fopen");
    }
    else
    {
        printf("文件打开成功\n");
        printf("文件描述符: %d\n", fileno(fp));
        printf("开始写入文件:\n");
        for (size_t i = 0; i < 5; i++)
        {
            /**
             * func descp: 写入一百行hello world
             */
            fputs("hello world\n", fp);
        }
        for (size_t i = 0; i < 5; i++)
        {
            /**
             * func descp: 写入一百个a
             */
            fputc('a', fp);
        }
        fputc('\n', fp);
        string str = "1234567890\n";
        fprintf(fp, "%s", str);
        /**
         * func descp: fwrite 函数的作用是把 __ptr 所指向的数组中的数据写入到指定的流 __s 中。它会以 __size 为单位，将 __n 个这样的单位数据从 __ptr 指向的内存区域写入到文件流 __s 里。
         */
        string str2 = "abcdefghij\n";
        fwrite(str2, strlen(str2), 1, fp);
        printf("开始读取文件:\n");
        rewind(fp);
        char buf[1024] = {0};
        int offset = 0;
        for (size_t i = 0; i < 11; i++)
        {
            fgets(buf + offset, 1024 - offset, fp); // 注意剩余缓冲区大小

            for (; buf[offset] != '\n' && buf[offset] != '\0'; offset++)
            {
                // 防止越界
            }
            // 去除读到的末尾的换行符
            if (buf[offset] == '\n')
            {
                buf[offset] = '\0';
            }
            offset = strlen(buf);
            printf("buf: %s\n", buf);
        }
        rewind(fp);

        /**
         * func descp: 测试fscanf
         */
        char buf2[1024] = {0};
        int offset2 = 0;
        for (size_t i = 0; i < 11; i++)
        {
            /**
             * func descp: 还是保持了scanf系列的特性，遇到空格和制表符换行符就会停止读取 天然的空格处理机制！
             */
            fscanf(fp, "%s", buf2 + offset2);
            offset2 = strlen(buf2);
            printf("buf2: %s\n", buf2);
        }
        fclose(fp);
    }
}