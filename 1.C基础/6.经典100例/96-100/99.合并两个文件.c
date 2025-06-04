/**
 * filename:99.合并两个文件.c
 * description: 题目：有两个磁盘文件A和B,各存放一行字母，要求把这两个文件中的信息合并（按字母顺序排列），输出到一个新文件C中。
 * author:EthanYankang
 * create time:2025/05/05 00:09:47
 */

#include <stdio.h>
#include <string.h>
void write2file(FILE *fp)
{
    printf("请输入字符，输入'!'结束写入:\n");
    char ch;
    while ((ch = getchar()) != '!')
    {
        fputc(ch, fp);
    }
    printf("%p写入文件完毕!\n", fp);
}

void read4file(FILE *fp, char *dest)
{
    char ch;
    while ((ch = fgetc(fp)) != EOF)
    {
        strcat(dest, &ch);
    }
}

int main()
{
    FILE *fp1 = fopen("/home/eyk/桌面/MCU/1.C基础/6.经典100例/96-100/99_1.txt", "w+");
    FILE *fp2 = fopen("/home/eyk/桌面/MCU/1.C基础/6.经典100例/96-100/99_2.txt", "w+");
    FILE *fp3 = fopen("/home/eyk/桌面/MCU/1.C基础/6.经典100例/96-100/99_0.txt", "w+");
    write2file(fp1);
    write2file(fp2);
    rewind(fp1);
    rewind(fp2);
    char dest[1000] = {0}; // 记得初始化，否则乱码
    read4file(fp1, dest);
    read4file(fp2, dest);
    printf("合并后的字符串为:\n%s\n", dest);

    // 排序dest
    for (int i = 0; i < strlen(dest); i++)
    {

        for (int j = i + 1; j < strlen(dest); j++)
        {
            if (dest[i] > dest[j])
            {
                char temp = dest[i];
                dest[i] = dest[j];
                dest[j] = temp;
            }
        }
    }
    printf("排序后的字符串为:\n%s\n  ", dest);
    // 写入文件
    for (int i = 0; i < strlen(dest); i++)
    {
        fputc(dest[i], fp3);
    }
    rewind(fp3);
    char ch;
    printf("写入文件的字符有:\n");
    while ((ch = fgetc(fp3)) != EOF)
    {
        putchar(ch);
    }
    puts("");
}
